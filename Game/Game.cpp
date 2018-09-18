//
// Game.cpp
//

#include "Game.h"

#include "Scenes/SampleScene.h"

using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="hInstance"></param>
/// <param name="nCmdShow"></param>
Game::Game(HINSTANCE hInstance, int nCmdShow)
	: Framework(hInstance, nCmdShow, L"���񂲑�Ƒ�")
{
	m_pSceneManager = nullptr;
	m_pNode = nullptr;
}

/// <summary>
/// ����������
/// </summary>
void Game::Initialize()
{
	// �V�[���}�l�[�W���[���쐬
	m_pSceneManager = std::make_unique<Scene::SceneManager>();
	// �V�[����o�^����
	m_pSceneManager->EntryScene(new SampleScene(m_pSceneManager.get()));
	// �J�n�V�[����ݒ肷��
	m_pSceneManager->StartScene("SampleScene");

	// �m�[�h���쐬
	m_pNode = std::make_unique<Node>();
}

/// <summary>
/// �I������
/// </summary>
void Game::Finalize()
{
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="timer"></param>
void Game::Update(DX::StepTimer const& timer)
{
	// �o�ߎ���
	float elapsedTime = float(timer.GetElapsedSeconds());

	// �V�[���}�l�[�W���[�̍X�V
	m_pSceneManager->UpdateActiveScene(elapsedTime);

	// �m�[�h�̍X�V
	m_pNode->UpdateAll(elapsedTime);
}

/// <summary>
/// �`�揈��
/// </summary>
void Game::Render()
{
	// �V�[���}�l�[�W���[�̕`��
	m_pSceneManager->RenderActiveScene();

	// �m�[�h�̕`��
	m_pNode->DrawAll();
}
