//
// SampleScene.h
//
#pragma once

#include "../../MyLibrary/MyLibrary.h"

namespace MyGame
{
	/// <summary>
	/// サンプルシーン
	/// </summary>
	class SampleScene : public MyLibrary::Scene::SceneBase
	{
	public:

		// コンストラクタ
		SampleScene(MyLibrary::Scene::SceneManager* pSceneManager);

		// デストラクタ
		~SampleScene();

		// 初期化処理
		void Initialize() override;

		// 更新処理
		void Update(float elapsedTime) override;

		// 描画処理
		void Render() override;

		// 終了処理
		void Finalize() override;
	};
}
