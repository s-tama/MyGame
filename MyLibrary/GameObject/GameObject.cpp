//
// GameObject.cpp
//

#include "GameObject.h"

using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
GameObject::GameObject()
{
	m_pTransform = new Transform();
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
GameObject::~GameObject()
{
}
