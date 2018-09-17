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
	/// �t���[�����[�N
	/// </summary>
	class Framework : public DX::IDeviceNotify
	{
	public:

		// �R���X�g���N�^
		Framework(HINSTANCE hInstance, int nCmdShow, const wchar_t* pGameName = L"WWWWWWWW", int width = 800, int height = 600);

		// �E�B���h�E�v���Z�X
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		// ����������
		virtual void Initialize() = 0;
		// �I������
		virtual void Finalize() = 0;

		// ��ʐF��ݒ�
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

		// �X�V����
		virtual void Update(DX::StepTimer const& timer) = 0;
		// �`�揈��
		virtual void Render() = 0;
		// �������g��`��
		void DoRender();

		// ��ʂ��N���A
		void Clear();

		// �f�o�C�X�̍쐬����
		void CreateDeviceDependentResources();
		// �E�B���h�E�̍쐬����
		void CreateWindowSizeDependentResources();


	protected:

		// �f�o�C�X���\�[�X�ւ̃|�C���^
		std::unique_ptr<DX::DeviceResources> m_pDeviceResources;

		// �X�e�b�v�^�C�}�[
		DX::StepTimer m_timer;

		// �R�����X�e�[�g
		std::unique_ptr<DirectX::CommonStates> m_pCommonStates;

		// �r���[�s��
		DirectX::SimpleMath::Matrix m_view;

		// �ˉe�s��
		DirectX::SimpleMath::Matrix m_projection;

		// ��ʕ�
		int m_screenWidth;
		// ��ʍ���
		int m_screenHeight;
		// ��ʐF
		const float* m_screenColor;
	};
}
