//
// SceneManager.cpp
//

#include <assert.h>
#include <Windows.h>

#include "SceneManager.h"
#include "SceneBase.h"

using namespace MyLibrary;
using namespace Scene;

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
	: m_pActiveScene(nullptr)
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{
	m_pActiveScene = nullptr;

	for (auto scenes : m_pSceneMap)
	{
		delete scenes.second;
		scenes.second = nullptr;
	}
}

/// <summary>
/// シーンを登録する
/// </summary>
/// <param name="pEntryScene"></param>
void SceneManager::EntryScene(SceneBase* pEntryScene)
{
	for (auto scenes : m_pSceneMap)
	{
		/*if (scenes.first == pEntryScene->GetName())
		{
			MessageBox(NULL, TEXT("シーンが重複しています"), TEXT("メッセージボックス"), MB_OK);
		}*/
		assert((scenes.first != pEntryScene->GetName()) && "シーンが重複しています");
	}

	// 登録する
	m_pSceneMap[pEntryScene->GetName()] = pEntryScene;
}

/// <summary>
/// 開始時のシーンを設定
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::StartScene(std::string sceneName)
{
	// 活動中のシーンに登録する
	m_pActiveScene = m_pSceneMap[sceneName];

	// 初期化する
	m_pActiveScene->Initialize();
}

/// <summary>
/// シーンを変更する
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::ChangeScene(std::string sceneName)
{
	// 現在活動中のシーンを終了する
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Finalize();
	}

	// 活動中のシーンに要求されたシーンを登録する
	m_pActiveScene = m_pSceneMap[sceneName];

	// 活動中のシーンを初期化する
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Initialize();
	}
}

/// <summary>
/// 活動中のシーンの更新
/// </summary>
void SceneManager::UpdateActiveScene(float elapsedTime)
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Update(elapsedTime);
	}
}

/// <summary>
/// 活動中のシーンの描画
/// </summary>
void SceneManager::RenderActiveScene()
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Render();
	}
}

/// <summary>
/// 活動中のシーンの取得
/// </summary>
/// <returns></returns>
SceneBase* SceneManager::GetActiveScene()
{
	return m_pActiveScene;
}
