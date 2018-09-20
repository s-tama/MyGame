//
// GameObject.cpp
//

#include "GameObject.h"

using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
GameObject::GameObject()
	: m_tag(NULL), m_pGameObject(this), m_pTransform(nullptr)
{
	m_pTransform = new Transform();
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="tag"></param>
GameObject::GameObject(std::string tag)
	: m_tag(tag), m_pGameObject(this), m_pTransform(nullptr)
{
	m_pTransform = new Transform();
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
GameObject::~GameObject()
{
}
