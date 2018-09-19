//
// GameObject.h
//
#pragma once

#include <vector>

#include "../Node/Node.h"
#include "../Component/Component.h"
#include "../Component/Transform.h"

namespace MyLibrary
{
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

		// �R���|�l���g��ǉ�
		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			m_pComponents.push_back(component);
			return component;
		}

		// �R���|�[�l���g���擾
		template <typename T>
		T* GetComponent()
		{
			for (auto components : m_pComponents)
			{
				if (dynamic_cast<T>(*components))
				{
					return (T*)m_pComponents;
				}
			}
			return nullptr;
		}

		// �g�����X�t�H�[����ݒ�
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		// �g�����X�t�H�[�����擾
		Transform* GetTransform() { return m_pTransform; }


	protected:

		// �R���|�[�l���g���X�g
		std::vector<Component*> m_pComponents;

		// �g�����X�t�H�[��
		Transform* m_pTransform;
	};
}
