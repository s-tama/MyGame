//
// Node.h
//
#pragma once

#include <list>

namespace MyLibrary
{
	/// <summary>
	/// ゲームオブジェクト管理ノードクラス
	/// </summary>
	class Node
	{
	public:

		// コンストラクタ
		Node();

		// 仮想デストラクタ
		virtual ~Node();

		// 子を追加
		void AddChild(Node* pNode);

		// 初期化する
		void InitializeAll();

		// 更新する
		void UpdateAll(float elapsedTime);

		// 描画する
		void DrawAll();

		
	private:

		// 自身の初期化処理
		virtual void Initialize();

		// 自身の更新処理
		virtual void Update(float elapsedTime);

		// 自身の描画処理
		virtual void Draw();


	private:

		// 子ノード
		std::list<Node*> m_pChildren;
	};
}
