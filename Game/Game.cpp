//
// Game.cpp
//

#include "Game.h"

#include "Scenes/SampleScene.h"

using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="hInstance"></param>
/// <param name="nCmdShow"></param>
Game::Game(HINSTANCE hInstance, int nCmdShow)
	: Framework(hInstance, nCmdShow, L"だんご大家族")
{
	m_pSceneManager = nullptr;
	m_pNode = nullptr;
}

/// <summary>
/// 初期化処理
/// </summary>
void Game::Initialize()
{
	// シーンマネージャーを作成
	m_pSceneManager = std::make_unique<Scene::SceneManager>();
	// シーンを登録する
	m_pSceneManager->EntryScene(new SampleScene(m_pSceneManager.get()));
	// 開始シーンを設定する
	m_pSceneManager->StartScene("SampleScene");

	// ノードを作成
	m_pNode = std::make_unique<Node>();
}

/// <summary>
/// 終了処理
/// </summary>
void Game::Finalize()
{
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="timer"></param>
void Game::Update(DX::StepTimer const& timer)
{
	// 経過時間
	float elapsedTime = float(timer.GetElapsedSeconds());

	// シーンマネージャーの更新
	m_pSceneManager->UpdateActiveScene(elapsedTime);

	// ノードの更新
	m_pNode->UpdateAll(elapsedTime);
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render()
{
	// シーンマネージャーの描画
	m_pSceneManager->RenderActiveScene();

	// ノードの描画
	m_pNode->DrawAll();
}
