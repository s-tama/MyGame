//
// Framework.h
//
#pragma once

#include <CommonStates.h>

#include "../Common/DeviceResources.h"
#include "../Common/StepTimer.h"

namespace MyLibrary
{
	/// <summary>
	/// フレームワーク
	/// </summary>
	class Framework : public DX::IDeviceNotify
	{
	public:

		// コンストラクタ
		Framework(HINSTANCE hInstance, int nCmdShow, const wchar_t* pGameName = L"WWWWWWWW", int width = 800, int height = 600);

		// ウィンドウプロセス
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		// 初期化処理
		virtual void Initialize() = 0;
		// 終了処理
		virtual void Finalize() = 0;

		// 画面色を設定
		void SetScreenColor(const float* color = DirectX::Colors::DarkBlue);

		// Basic game loop
		void Tick();

		// IDeviceNotify
		virtual void OnDeviceLost() override;
		virtual void OnDeviceRestored() override;

		// Messages
		void OnActivated();
		void OnDeactivated();
		void OnSuspending();
		void OnResuming();
		void OnWindowMoved();
		void OnWindowSizeChanged(int width, int height);

		// Properties
		void GetDefaultSize(int& width, int& height) const;


	private:

		// 更新処理
		virtual void Update(DX::StepTimer const& timer) = 0;
		// 描画処理
		virtual void Render() = 0;
		// 自分自身を描画
		void DoRender();

		// 画面をクリア
		void Clear();

		// デバイスの作成処理
		void CreateDeviceDependentResources();
		// ウィンドウの作成処理
		void CreateWindowSizeDependentResources();


	protected:

		// デバイスリソースへのポインタ
		std::unique_ptr<DX::DeviceResources> m_pDeviceResources;

		// ステップタイマー
		DX::StepTimer m_timer;

		// コモンステート
		std::unique_ptr<DirectX::CommonStates> m_pCommonStates;

		// ビュー行列
		DirectX::SimpleMath::Matrix m_view;

		// 射影行列
		DirectX::SimpleMath::Matrix m_projection;

		// 画面幅
		int m_screenWidth;
		// 画面高さ
		int m_screenHeight;
		// 画面色
		const float* m_screenColor;
	};
}
