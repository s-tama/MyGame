//
// Main.cpp
//

#include "MyLibrary\MyLibrary.h"
#include "Game\Game.h"

using namespace DirectX;
using namespace MyLibrary;

// Indicates to hybrid graphics systems to prefer the discrete part by default
extern "C"
{
    __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

// Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	// フレームワークへのポインタ
	std::unique_ptr<MyLibrary::Framework> framework;

    if (!XMVerifyCPUSupport())
        return 1;

    HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
    if (FAILED(hr))
        return 1;

	// フレームワークを作成
    framework = std::make_unique<Game>(hInstance, nCmdShow);

    // Register class and create window
    {
		// 初期化処理
		framework->Initialize();
    }

    // Main message loop
    MSG msg = {};
    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
			framework->Tick();
        }
    }

	// 終了処理
	framework->Finalize();
	framework.reset();

    CoUninitialize();

    return (int) msg.wParam;
}

// Exit helper
void ExitGame()
{
    PostQuitMessage(0);
}