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

		// 全てを更新する
		void UpdateAll(float elapsedTime);

		// 全て描画する
		void DrawAll();

		
	private:

		virtual void Update(float elapsedTime);

		// 自身の描画処理
		virtual void Draw();


	private:

		// 子ノード
		std::list<Node*> m_pChildren;
	};
}
