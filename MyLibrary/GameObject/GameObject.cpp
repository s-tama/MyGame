//
// GameObject.cpp
//

#include "GameObject.h"

using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
GameObject::GameObject()
	: m_tag(NULL)
{
	m_pTransform = new Transform();
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="tag"></param>
GameObject::GameObject(std::string tag)
	: m_tag(tag)
{
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
GameObject::~GameObject()
{
}
