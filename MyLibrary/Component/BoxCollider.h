//
// BoxCollider.h
//
#pragma once

#include "Collider.h"

namespace MyLibrary
{
	/// <summary>
	/// �{�b�N�X�R���C�_�N���X
	/// </summary>
	class BoxCollider : public Collider
	{
	public:

		// �R���X�g���N�^
		BoxCollider();
		// �R�s�[�R���X�g���N�^
		BoxCollider(DirectX::SimpleMath::Vector3 center, DirectX::SimpleMath::Vector3 extents, DirectX::SimpleMath::Vector3 size);


	private:

		// ���S�_
		DirectX::SimpleMath::Vector3 m_center;

		// �L��
		DirectX::SimpleMath::Vector3 m_extents;

		// �傫��
		DirectX::SimpleMath::Vector3 m_size;
	};
}
