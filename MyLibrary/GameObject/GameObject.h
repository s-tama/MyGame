//
// GameObject.h
//
#pragma once

#include "../Node/Node.h"

namespace MyLibrary
{
	// �N���X�錾
	class Component;

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�N���X
	/// </summary>
	class GameObject : public Node
	{
	public:

		// �R���X�g���N�^
		GameObject();

		// ���z�f�X�g���N�^
		virtual ~GameObject();

		// �R���|�[�l���g���擾
		template <typename T>
		T GetComponent(T component) { return component; }


	private:
	};
}
