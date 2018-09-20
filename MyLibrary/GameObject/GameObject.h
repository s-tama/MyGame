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
	/// ゲームオブジェクトクラス
	/// </summary>
	class GameObject : public Node
	{
	public:

		// コンストラクタ
		GameObject();
		// コピーコンストラクタ
		GameObject(std::string tag);

		// 仮想デストラクタ
		virtual ~GameObject();

		// 当たっている間
		virtual void OnCollisionStay(Collider* collider){}
		// 当たった瞬間
		virtual void OnCollisionEnter(Collider* collider){}
		// 離れた時
		virtual void OnCollisionExit(Collider* collision){}

		// コンポネントを追加
		template <typename T>
		void AddComponent()
		{
			Component* component = new T();
			component->SetGameObject(this);
			component->SetTransform(m_pTransform);
			m_pComponents.push_back(component);
		}

		// コンポーネントを取得
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

		// トランスフォームを設定
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		// トランスフォームを取得
		Transform* GetTransform() { return m_pTransform; }

		// ゲームオブジェクトの取得
		GameObject* GetGameObject() { return m_pGameObject; }

		// タグ名の取得
		std::string GetTag() { return m_tag; }

		
	protected:

		// タグ
		std::string m_tag;

		// 自己参照
		GameObject* m_pGameObject;

		// トランスフォーム
		Transform* m_pTransform;

		// コンポーネントリスト
		std::vector<Component*> m_pComponents;
	};
}
