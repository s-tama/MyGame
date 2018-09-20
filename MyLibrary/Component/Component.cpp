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
	: m_pGameObject(nullptr), m_pTransform(nullptr)
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
