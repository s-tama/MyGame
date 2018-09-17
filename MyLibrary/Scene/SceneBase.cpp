//
// Scene.cpp
//

#include "SceneBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pSceneManager">シーンマネージャーへのポインタ</param>
MyLibrary::Scene::SceneBase::SceneBase(SceneManager* pSceneManager, std::string name)
	: m_pScenemanager(pSceneManager), m_name(name)
{
}

/// <summary>
/// デストラクタ
/// </summary>
MyLibrary::Scene::SceneBase::~SceneBase()
{
}

/// <summary>
/// 名前の取得
/// </summary>
/// <returns></returns>
std::string MyLibrary::Scene::SceneBase::GetName()
{
	return m_name;
}
