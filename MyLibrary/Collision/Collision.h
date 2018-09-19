//
// Collision.h
//
#pragma once

#include "../Utility/Flag.h"

namespace MyLibrary
{
	// �N���X�錾
	class SphereCollider;
	class GameObject;

	/// <summary>
	/// �����蔻��N���X
	/// </summary>
	class Collision
	{
	public:

		// �R���X�g���N�^
		Collision();

		// ���Ƌ��̓����蔻��
		static void Sphere2Sphere(SphereCollider* sphere1, SphereCollider* sphere2);
	};
}
