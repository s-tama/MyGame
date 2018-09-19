//
// Collision.cpp
//

#include "Collision.h"

#include "../Component/SphereCollider.h"
#include "../Component/Transform.h"
#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
MyLibrary::Collision::Collision()
{
}

/// <summary>
/// 球と球の当たり判定
/// </summary>
/// <param name="sphere1"></param>
/// <param name="sphere2"></param>
void Collision::Sphere2Sphere(SphereCollider* sphere1, SphereCollider* sphere2)
{
	if (sphere1 && sphere2)
	{
		float dx = sphere1->GetTransform()->GetPosition().x - sphere2->GetTransform()->GetPosition().x;
		float dy = sphere1->GetTransform()->GetPosition().y - sphere2->GetTransform()->GetPosition().y;
		float dz = sphere1->GetTransform()->GetPosition().z - sphere2->GetTransform()->GetPosition().z;
		float d = sphere1->GetRadius() + sphere2->GetRadius();

		float dx2 = dx * dx;
		float dy2 = dy * dy;
		float dz2 = dz * dz;
		float d2 = d*d;

		if (dx2 + dy2 + dz2 <= d2)
		{
			// 当たり判定を実行
			sphere1->GetGameObject()->OnCollisionStay(sphere2);
		}
	}
}
