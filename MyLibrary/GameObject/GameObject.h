//
// GameObject.h
//
#pragma once

#include <string>
#include <vector>

#include "../Node/Node.h"
#include "../Component/Component.h"
#include "../Component/Transform.h"
#include "../Collision/Collision.h"
#include "../Component/Collider.h"
#include "../Component/Rigidbody.h"
#include "../Component/SphereCollider.h"

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
		// �R�s�[�R���X�g���N�^
		GameObject(std::string tag);

		// ���z�f�X�g���N�^
		virtual ~GameObject();

		// �������Ă����
		virtual void OnCollisionStay(Collider* collider){}
		// ���������u��
		virtual void OnCollisionEnter(Collider* collider){}
		// ���ꂽ��
		virtual void OnCollisionExit(Collider* collision){}

		// �R���|�l���g��ǉ�
		template <typename T>
		void AddComponent()
		{
			Component* component = new T();
			component->SetGameObject(this);
			component->SetTransform(m_pTransform);
			m_pComponents.push_back(component);
		}

		// �R���|�[�l���g���擾
		template <typename T>
		T* GetComponent()
		{
			for (auto components : m_pComponents)
			{
				if (dynamic_cast<T*>(components))
				{
					return (T*)components;
				}
			}
			return nullptr;
		}

		// �g�����X�t�H�[����ݒ�
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		// �g�����X�t�H�[�����擾
		Transform* GetTransform() { return m_pTransform; }

		// �Q�[���I�u�W�F�N�g�̎擾
		GameObject* GetGameObject() { return m_pGameObject; }

		// �^�O���̎擾
		std::string GetTag() { return m_tag; }

		
	protected:

		// �^�O
		std::string m_tag;

		// ���ȎQ��
		GameObject* m_pGameObject;

		// �g�����X�t�H�[��
		Transform* m_pTransform;

		// �R���|�[�l���g���X�g
		std::vector<Component*> m_pComponents;
	};
}
