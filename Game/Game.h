//
// Game.h
//

#pragma once

#include "../MyLibrary/MyLibrary.h"

/// <summary>
/// ゲームクラス
/// </summary>
class Game : public MyLibrary::Framework
{
public:

	// コンストラクタ
	Game(HINSTANCE hInstance, int nCmdShow);

	// 初期化処理
	void Initialize() override;

	// 終了処理
	void Finalize() override;


private:

	// 更新処理
	void Update(DX::StepTimer const& timer);

	// 描画処理
	void Render();

	// シーンマネージャー
	std::unique_ptr<MyLibrary::Scene::SceneManager> m_pSceneManager;
};