//
// Framework.cpp
//

#include "../pch.h"
#include "Framework.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="window"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Framework::Framework(HINSTANCE hInstance, int nCmdShow, const wchar_t* pGameName, int width, int height)
	: m_screenWidth(width), m_screenHeight(height), m_screenColor(Colors::DarkBlue)
{
	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, L"IDI_ICON");
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"MyGameWindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, L"IDI_ICON");
	if (!RegisterClassEx(&wcex))
		throw 0;

	// Create window
	int w, h;
	GetDefaultSize(w, h);

	RECT rc;
	rc.top = 0;
	rc.left = 0;
	rc.right = static_cast<LONG>(w);
	rc.bottom = static_cast<LONG>(h);

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hWnd = CreateWindowEx(0, L"MyGameWindowClass", pGameName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
		nullptr);
	// TODO: Change to CreateWindowEx(WS_EX_TOPMOST, L"MyGameWindowClass", L"MyGame", WS_POPUP,
	// to default to fullscreen.

	if (!hWnd)
		throw 0;

	ShowWindow(hWnd, nCmdShow);
	// TODO: Change nCmdShow to SW_SHOWMAXIMIZED to default to fullscreen.

	SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	GetClientRect(hWnd, &rc);
	

	// デバイスリソースの作成
	m_pDeviceResources = std::make_unique<DX::DeviceResources>();
	m_pDeviceResources->RegisterDeviceNotify(this);

	m_pDeviceResources->SetWindow(hWnd, w, h);

	m_pDeviceResources->CreateDeviceResources();
	CreateDeviceDependentResources();

	m_pDeviceResources->CreateWindowSizeDependentResources();
	CreateWindowSizeDependentResources();
}

/// <summary>
/// ウィンドウプロセス
/// </summary>
/// <param name="hWnd"></param>
/// <param name="message"></param>
/// <param name="wParam"></param>
/// <param name="lParam"></param>
/// <returns></returns>
LRESULT Framework::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	static bool s_in_sizemove = false;
	static bool s_in_suspend = false;
	static bool s_minimized = false;
	static bool s_fullscreen = false;
	// TODO: Set s_fullscreen to true if defaulting to fullscreen.

	auto framework = reinterpret_cast<Framework*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_PAINT:
		if (s_in_sizemove && framework)
		{
			framework->Tick();
		}
		else
		{
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
		}
		break;

	case WM_MOVE:
		if (framework)
		{
			framework->OnWindowMoved();
		}
		break;

	case WM_SIZE:
		if (wParam == SIZE_MINIMIZED)
		{
			if (!s_minimized)
			{
				s_minimized = true;
				if (!s_in_suspend && framework)
					framework->OnSuspending();
				s_in_suspend = true;
			}
		}
		else if (s_minimized)
		{
			s_minimized = false;
			if (s_in_suspend && framework)
				framework->OnResuming();
			s_in_suspend = false;
		}
		else if (!s_in_sizemove && framework)
		{
			framework->OnWindowSizeChanged(LOWORD(lParam), HIWORD(lParam));
		}
		break;

	case WM_ENTERSIZEMOVE:
		s_in_sizemove = true;
		break;

	case WM_EXITSIZEMOVE:
		s_in_sizemove = false;
		if (framework)
		{
			RECT rc;
			GetClientRect(hWnd, &rc);

			framework->OnWindowSizeChanged(rc.right - rc.left, rc.bottom - rc.top);
		}
		break;

	case WM_GETMINMAXINFO:
	{
		auto info = reinterpret_cast<MINMAXINFO*>(lParam);
		info->ptMinTrackSize.x = 320;
		info->ptMinTrackSize.y = 200;
	}
	break;

	case WM_ACTIVATEAPP:
		if (framework)
		{
			if (wParam)
			{
				framework->OnActivated();
			}
			else
			{
				framework->OnDeactivated();
			}
		}
		break;

	case WM_POWERBROADCAST:
		switch (wParam)
		{
		case PBT_APMQUERYSUSPEND:
			if (!s_in_suspend && framework)
				framework->OnSuspending();
			s_in_suspend = true;
			return TRUE;

		case PBT_APMRESUMESUSPEND:
			if (!s_minimized)
			{
				if (s_in_suspend && framework)
					framework->OnResuming();
				s_in_suspend = false;
			}
			return TRUE;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_SYSKEYDOWN:
		if (wParam == VK_RETURN && (lParam & 0x60000000) == 0x20000000)
		{
			// Implements the classic ALT+ENTER fullscreen toggle
			if (s_fullscreen)
			{
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
				SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);

				int width = 800;
				int height = 600;
				if (framework)
					framework->GetDefaultSize(width, height);

				ShowWindow(hWnd, SW_SHOWNORMAL);

				SetWindowPos(hWnd, HWND_TOP, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
			}
			else
			{
				SetWindowLongPtr(hWnd, GWL_STYLE, 0);
				SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_TOPMOST);

				SetWindowPos(hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

				ShowWindow(hWnd, SW_SHOWMAXIMIZED);
			}

			s_fullscreen = !s_fullscreen;
		}
		break;

	case WM_MENUCHAR:
		// A menu is active and the user presses a key that does not correspond
		// to any mnemonic or accelerator key. Ignore so we don't produce an error beep.
		return MAKELRESULT(0, MNC_CLOSE);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

/// <summary>
/// 画面色を設定
/// </summary>
/// <param name="color"></param>
void Framework::SetScreenColor(const float* color)
{
	m_screenColor = color;
}

/// <summary>
/// 
/// </summary>
void Framework::Tick()
{
	m_timer.Tick([&]()
	{
		Update(m_timer);
	});

	// 描画
	DoRender();
}

/// <summary>
/// デバイスロスト時に行う処理
/// </summary>
void Framework::OnDeviceLost()
{
}

/// <summary>
/// 
/// </summary>
void Framework::OnDeviceRestored()
{
	CreateDeviceDependentResources();

	CreateWindowSizeDependentResources();
}

/// <summary>
/// 
/// </summary>
void Framework::OnActivated()
{
}

/// <summary>
/// 
/// </summary>
void Framework::OnDeactivated()
{
}

/// <summary>
/// 
/// </summary>
void MyLibrary::Framework::OnSuspending()
{
}

/// <summary>
/// 
/// </summary>
void MyLibrary::Framework::OnResuming()
{
}

/// <summary>
/// 
/// </summary>
void MyLibrary::Framework::OnWindowMoved()
{
	auto r = m_pDeviceResources->GetOutputSize();
	m_pDeviceResources->WindowSizeChanged(r.right, r.bottom);
}

/// <summary>
/// 
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Framework::OnWindowSizeChanged(int width, int height)
{
	auto r = m_pDeviceResources->GetOutputSize();
	m_pDeviceResources->WindowSizeChanged(r.right, r.bottom);
}

/// <summary>
/// 
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Framework::GetDefaultSize(int & width, int & height) const
{
	width = m_screenWidth;
	height = m_screenHeight;
}

/// <summary>
/// 自分自身を描画
/// </summary>
void Framework::DoRender()
{
	// Don't try to render anything before the first Update.
	if (m_timer.GetFrameCount() == 0)
	{
		return;
	}

	Clear();

	m_pDeviceResources->PIXBeginEvent(L"Render");
	auto context = m_pDeviceResources->GetD3DDeviceContext();

	// 描画処理
	Render();

	m_pDeviceResources->PIXEndEvent();

	// Show the new frame.
	m_pDeviceResources->Present();
}

/// <summary>
/// 画面をクリア
/// </summary>
void Framework::Clear()
{
	m_pDeviceResources->PIXBeginEvent(L"Clear");

	// Clear the views.
	auto context = m_pDeviceResources->GetD3DDeviceContext();
	auto renderTarget = m_pDeviceResources->GetRenderTargetView();
	auto depthStencil = m_pDeviceResources->GetDepthStencilView();

	context->ClearRenderTargetView(renderTarget, m_screenColor);
	context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	context->OMSetRenderTargets(1, &renderTarget, depthStencil);

	// Set the viewport.
	auto viewport = m_pDeviceResources->GetScreenViewport();
	context->RSSetViewports(1, &viewport);

	m_pDeviceResources->PIXEndEvent();
}

/// <summary>
/// デバイスの作成処理
/// </summary>
void Framework::CreateDeviceDependentResources()
{
	// デバイス
	ID3D11Device* pDevice = m_pDeviceResources->GetD3DDevice();
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = m_pDeviceResources->GetD3DDeviceContext();

	// コモンステートを作成
	m_pCommonStates = std::make_unique<CommonStates>(pDevice);
}

/// <summary>
/// ウィンドウサイズの作成処理
/// </summary>
void Framework::CreateWindowSizeDependentResources()
{
}
