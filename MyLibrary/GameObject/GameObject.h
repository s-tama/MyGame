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
	/// ゲームオブジェクトクラス
	/// </summary>
	class GameObject : public Node
	{
	public:

		// コンストラクタ
		GameObject();

		// 仮想デストラクタ
		virtual ~GameObject();

		// コンポネントを追加
		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			m_pComponents.push_back(component);
			return component;
		}

		// コンポーネントを取得
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

		// トランスフォームを設定
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		// トランスフォームを取得
		Transform* GetTransform() { return m_pTransform; }


	protected:

		// コンポーネントリスト
		std::vector<Component*> m_pComponents;

		// トランスフォーム
		Transform* m_pTransform;
	};
}
