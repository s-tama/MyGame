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

/// <summary>
/// トランスフォームの取得
/// </summary>
/// <returns></returns>
Transform * MyLibrary::Component::GetTransform()
{
	return m_pTransform;
}

/// <summary>
/// トランスフォームの設定
/// </summary>
/// <param name="pTransform"></param>
void Component::SetTransform(Transform* pTransform)
{
	m_pTransform = pTransform;
}
