//
// Collider.h
//
#pragma once

#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// �R���C�_�[�N���X
	/// </summary>
	class Collider : public Component
	{
	public:

		// �R���X�g���N�^
		Collider();

		// ���z�f�X�g���N�^
		virtual ~Collider();
	};
}
