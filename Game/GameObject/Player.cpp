//
// Player.cpp
//

#include "Player.h"

using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
	: GameObject("Player")
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Player::Initialize()
{
	// リジッドボディを追加
	this->AddComponent<Rigidbody>();

	// スフィアコライダを追加
	this->AddComponent<SphereCollider>();
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Player::Update(float elapsedTime)
{
	// リジッドボディ更新
	this->GetComponent<Rigidbody>()->Update(elapsedTime);
}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw()
{
}
