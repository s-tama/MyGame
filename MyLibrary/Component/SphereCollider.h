//
// SphereCollider.h
//
#pragma once

#include "../pch.h"
#include "Collider.h"

namespace MyLibrary
{
	/// <summary>
	/// 球のコライダクラス
	/// </summary>
	class SphereCollider : public Collider
	{
	public:

		// コンストラクタ
		SphereCollider();
		// コピーコンストラクタ
		SphereCollider(DirectX::SimpleMath::Vector3 center, float radius);

		// 中心点の取得
		DirectX::SimpleMath::Vector3 GetCenter() { return m_center; }

		// 半径の取得
		float GetRadius() { return m_radius; }


	private:

		// 中心点
		DirectX::SimpleMath::Vector3 m_center;

		// 半径
		float m_radius;
	};
}
