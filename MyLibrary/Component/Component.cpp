//
// Component.cpp
//

#include "../pch.h"
#include "Component.h"

#include "../GameObject/GameObject.h"
#include "Transform.h"

using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
Component::Component()
	: m_pGameObject(nullptr), m_pTransform(nullptr)
{
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
Component::~Component()
{
}

/// <summary>
/// ゲームオブジェクトの取得
/// </summary>
/// <returns></returns>
GameObject* Component::GetGameObject()
{
	return m_pGameObject;
}

/// <summary>
/// ゲームオブジェクトの設定
/// </summary>
/// <param name="pGameObject"></param>
void Component::SetGameObject(GameObject* pGameObject)
{
	m_pGameObject = pGameObject;
}
