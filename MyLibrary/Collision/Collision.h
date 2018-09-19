//
// Collision.h
//
#pragma once

#include "../Utility/Flag.h"

namespace MyLibrary
{
	// クラス宣言
	class SphereCollider;
	class GameObject;

	/// <summary>
	/// 当たり判定クラス
	/// </summary>
	class Collision
	{
	public:

		// コンストラクタ
		Collision();

		// 球と球の当たり判定
		static void Sphere2Sphere(SphereCollider* sphere1, SphereCollider* sphere2);
	};
}
