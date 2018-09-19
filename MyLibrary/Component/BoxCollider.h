//
// BoxCollider.h
//
#pragma once

#include "Collider.h"

namespace MyLibrary
{
	/// <summary>
	/// ボックスコライダクラス
	/// </summary>
	class BoxCollider : public Collider
	{
	public:

		// コンストラクタ
		BoxCollider();
		// コピーコンストラクタ
		BoxCollider(DirectX::SimpleMath::Vector3 center, DirectX::SimpleMath::Vector3 extents, DirectX::SimpleMath::Vector3 size);

		// 中心点の取得
		DirectX::SimpleMath::Vector3 GetCenter() { return m_center; }
		
		// 広さの取得
		DirectX::SimpleMath::Vector3 GetExtents() { return m_extents; }

		// 大きさの取得
		DirectX::SimpleMath::Vector3 GetSize() { return m_size; }


	private:

		// 中心点
		DirectX::SimpleMath::Vector3 m_center;

		// 広さ
		DirectX::SimpleMath::Vector3 m_extents;

		// 大きさ
		DirectX::SimpleMath::Vector3 m_size;
	};
}
