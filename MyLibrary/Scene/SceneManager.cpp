//
// SceneManager.cpp
//

#include <assert.h>
#include <Windows.h>

#include "SceneManager.h"
#include "SceneBase.h"

using namespace MyLibrary;
using namespace Scene;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager()
	: m_pActiveScene(nullptr)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager()
{
	m_pActiveScene = nullptr;

	for (auto scenes : m_pSceneMap)
	{
		delete scenes.second;
		scenes.second = nullptr;
	}
}

/// <summary>
/// �V�[����o�^����
/// </summary>
/// <param name="pEntryScene"></param>
void SceneManager::EntryScene(SceneBase* pEntryScene)
{
	for (auto scenes : m_pSceneMap)
	{
		/*if (scenes.first == pEntryScene->GetName())
		{
			MessageBox(NULL, TEXT("�V�[�����d�����Ă��܂�"), TEXT("���b�Z�[�W�{�b�N�X"), MB_OK);
		}*/
		assert((scenes.first != pEntryScene->GetName()) && "�V�[�����d�����Ă��܂�");
	}

	// �o�^����
	m_pSceneMap[pEntryScene->GetName()] = pEntryScene;
}

/// <summary>
/// �J�n���̃V�[����ݒ�
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::StartScene(std::string sceneName)
{
	// �������̃V�[���ɓo�^����
	m_pActiveScene = m_pSceneMap[sceneName];

	// ����������
	m_pActiveScene->Initialize();
}

/// <summary>
/// �V�[����ύX����
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::ChangeScene(std::string sceneName)
{
	// ���݊������̃V�[�����I������
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Finalize();
	}

	// �������̃V�[���ɗv�����ꂽ�V�[����o�^����
	m_pActiveScene = m_pSceneMap[sceneName];

	// �������̃V�[��������������
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Initialize();
	}
}

/// <summary>
/// �������̃V�[���̍X�V
/// </summary>
void SceneManager::UpdateActiveScene(float elapsedTime)
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Update(elapsedTime);
	}
}

/// <summary>
/// �������̃V�[���̕`��
/// </summary>
void SceneManager::RenderActiveScene()
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Render();
	}
}

/// <summary>
/// �������̃V�[���̎擾
/// </summary>
/// <returns></returns>
SceneBase* SceneManager::GetActiveScene()
{
	return m_pActiveScene;
}
