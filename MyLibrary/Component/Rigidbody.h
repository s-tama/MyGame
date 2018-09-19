//
// Rigidbody.h
//
#pragma once

#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// ���W�b�h�{�f�B
	/// </summary>
	class Rigidbody : public Component
	{
	public:

		// �R���X�g���N�^
		Rigidbody();

		// �X�V����
		void Update(float elapsedTime);


	private:

		// �d��
		float m_gravity;

		// ���x
		DirectX::SimpleMath::Vector3 m_velocity;
	};
}
