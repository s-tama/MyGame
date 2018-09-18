//
// GameObject.h
//
#pragma once

#include "../Node/Node.h"

namespace MyLibrary
{
	// クラス宣言
	class Component;

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

		// コンポーネントを取得
		template <typename T>
		T GetComponent(T component) { return component; }


	private:
	};
}
