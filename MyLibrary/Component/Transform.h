//
// Transform.h
//
#pragma once

#include "../pch.h"
#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// トランスフォームクラス
	/// </summary>
	class Transform : public Component
	{
	public:

		// コンストラクタ
		Transform();

		// デストラクタ
		~Transform();

		// 移動
		void Translate(DirectX::SimpleMath::Vector3 translate);
		void Translate(float x, float y, float z);

		// ワールド行列の取得
		DirectX::SimpleMath::Matrix GetWorld() { return m_world; }
		// ワールド行列の設定
		void SetWorld(DirectX::SimpleMath::Matrix world) { m_world = world; }

		// 座標を取得
		DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }
		// 座標を設定
		void SetPosition(DirectX::SimpleMath::Vector3 position) { m_position = position; }
		void SetPosition(float x, float y, float z) { m_position = DirectX::SimpleMath::Vector3(x, y, z); }

		// スケールを取得
		DirectX::SimpleMath::Vector3 GetScale() { return m_scale; }
		// スケールを設定
		void SetScale(DirectX::SimpleMath::Vector3 scale) { m_scale = scale; }
		void SetScale(float x, float y, float z) { m_scale = DirectX::SimpleMath::Vector3(x, y, z); }

		// 回転を取得
		DirectX::SimpleMath::Quaternion GetRotation() { return m_rotation; }


	private:

		// 座標
		DirectX::SimpleMath::Vector3 m_position;

		// スケール
		DirectX::SimpleMath::Vector3 m_scale;

		// 回転
		DirectX::SimpleMath::Quaternion m_rotation;

		// ワールド行列
		DirectX::SimpleMath::Matrix m_world;
	};
}