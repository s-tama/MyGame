//
// Component.cpp
//

#include "../pch.h"
#include "Component.h"

#include "../GameObject/GameObject.h"
#include "Transform.h"

using namespace MyLibrary;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Component::Component()
{
}

/// <summary>
/// ���z�f�X�g���N�^
/// </summary>
Component::~Component()
{
}

/// <summary>
/// �Q�[���I�u�W�F�N�g�̎擾
/// </summary>
/// <returns></returns>
GameObject* Component::GetGameObject()
{
	return m_pGameObject;
}

/// <summary>
/// �Q�[���I�u�W�F�N�g�̐ݒ�
/// </summary>
/// <param name="pGameObject"></param>
void Component::SetGameObject(GameObject* pGameObject)
{
	m_pGameObject = pGameObject;
}

/// <summary>
/// �g�����X�t�H�[���̎擾
/// </summary>
/// <returns></returns>
Transform * MyLibrary::Component::GetTransform()
{
	return m_pTransform;
}

/// <summary>
/// �g�����X�t�H�[���̐ݒ�
/// </summary>
/// <param name="pTransform"></param>
void Component::SetTransform(Transform* pTransform)
{
	m_pTransform = pTransform;
}
