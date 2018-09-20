//
// Collision.cpp
//

#include "Collision.h"

#include "../Component/SphereCollider.h"
#include "../Component/Transform.h"
#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;
using namespace Utility;

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
	float dx = sphere1->GetGameObject()->GetTransform()->GetPosition().x - sphere2->GetGameObject()->GetTransform()->GetPosition().x;
	float dy = sphere1->GetGameObject()->GetTransform()->GetPosition().y - sphere2->GetGameObject()->GetTransform()->GetPosition().y;
	float dz = sphere1->GetGameObject()->GetTransform()->GetPosition().z - sphere2->GetGameObject()->GetTransform()->GetPosition().z;
	float d = sphere1->GetRadius() + sphere2->GetRadius();

	float dx2 = dx * dx;
	float dy2 = dy * dy;
	float dz2 = dz * dz;
	float d2 = d*d;

	static bool currentHit;
	static bool lastHit;

	lastHit = currentHit;
	currentHit = dx2 + dy2 + dz2 <= d2;

	if (currentHit)
	{
		// 当たっている間
		sphere1->GetGameObject()->OnCollisionStay(sphere2);
	}

	if (!lastHit)
	{
		if (currentHit)
		{
			// 当たった瞬間
			sphere1->GetGameObject()->OnCollisionEnter(sphere2);
		}
	}
	else
	{
		if (!currentHit)
		{
			// 離れた瞬間
			sphere1->GetGameObject()->OnCollisionExit(sphere2);
		}
	}
}
