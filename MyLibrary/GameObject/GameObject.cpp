//
// GameObject.cpp
//

#include "GameObject.h"

using namespace MyLibrary;

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameObject::GameObject()
	: m_tag(NULL)
{
	m_pTransform = new Transform();
}

/// <summary>
/// �R�s�[�R���X�g���N�^
/// </summary>
/// <param name="tag"></param>
GameObject::GameObject(std::string tag)
	: m_tag(tag)
{
}

/// <summary>
/// ���z�f�X�g���N�^
/// </summary>
GameObject::~GameObject()
{
}
