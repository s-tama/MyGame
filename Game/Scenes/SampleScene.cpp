//
// SampleScene.cpp
//

#include "SampleScene.h"

using namespace MyLibrary;
using namespace MyLibrary::Scene;
using namespace MyGame;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pSceneManager">シーンマネージャーへのポインタ</param>
/// <param name="name">シーンの名前</param>
SampleScene::SampleScene(SceneManager* pSceneManager)
	: SceneBase(pSceneManager, "SampleScene")
{
}

/// <summary>
/// デストラクタ
/// </summary>
SampleScene::~SampleScene()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void SampleScene::Initialize()
{
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime"></param>
void SampleScene::Update(float elapsedTime)
{
}

/// <summary>
/// 描画処理
/// </summary>
void SampleScene::Render()
{
}

/// <summary>
/// 終了処理
/// </summary>
void SampleScene::Finalize()
{
}
