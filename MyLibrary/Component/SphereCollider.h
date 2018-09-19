//
// SphereCollider.h
//
#pragma once

#include "Collider.h"

namespace MyLibrary
{
	/// <summary>
	/// ���̃R���C�_�N���X
	/// </summary>
	class SphereCollider : public Collider
	{
	public:

		// �R���X�g���N�^
		SphereCollider();
		// �R�s�[�R���X�g���N�^
		SphereCollider(DirectX::SimpleMath::Vector3 center, float radius);

		// ���S�_�̎擾
		DirectX::SimpleMath::Vector3 GetCenter() { return m_center; }

		// ���a�̎擾
		float GetRadius() { return m_radius; }


	private:

		// ���S�_
		DirectX::SimpleMath::Vector3 m_center;

		// ���a
		float m_radius;
	};
}
