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


	private:

		// 中心点
		DirectX::SimpleMath::Vector3 m_center;

		// 広さ
		DirectX::SimpleMath::Vector3 m_extents;

		// 大きさ
		DirectX::SimpleMath::Vector3 m_size;
	};
}
