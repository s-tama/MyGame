//
// Scene.cpp
//

#include "SceneBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="pSceneManager">�V�[���}�l�[�W���[�ւ̃|�C���^</param>
MyLibrary::Scene::SceneBase::SceneBase(SceneManager* pSceneManager, std::string name)
	: m_pScenemanager(pSceneManager), m_name(name)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
MyLibrary::Scene::SceneBase::~SceneBase()
{
}

/// <summary>
/// ���O�̎擾
/// </summary>
/// <returns></returns>
std::string MyLibrary::Scene::SceneBase::GetName()
{
	return m_name;
}
