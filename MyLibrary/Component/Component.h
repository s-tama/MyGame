//
// Component.h
//
#pragma once

namespace MyLibrary
{
	// クラス宣言
	class Transform;
	class GameObject;

	/// <summary>
	/// コンポーネントクラス
	/// </summary>
	class Component
	{
	public:

		// コンストラクタ
		Component();

		// 仮想デストラクタ
		virtual ~Component();

		// ゲームオブジェクトの取得
		GameObject* GetGameObject();
		// ゲームオブジェクトの設定
		void SetGameObject(GameObject* pGameObject);

		// トランスフォームの取得
		Transform* GetTransform();
		// トランスフォームの設定
		void SetTransform(Transform* pTransform);


	protected:

		// トランスフォームへのポインタ
		Transform* m_pTransform;

		// ゲームオブジェクトへのポインタ
		GameObject* m_pGameObject;
	};
}
