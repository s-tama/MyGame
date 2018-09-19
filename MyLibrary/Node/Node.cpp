//
// Node.cpp
//

#include "Node.h"

using namespace MyLibrary;

/// <summary>
/// コンストラクタ
/// </summary>
Node::Node()
{
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
Node::~Node()
{
}

/// <summary>
/// 子を追加
/// </summary>
/// <param name="pNode">ノード</param>
void Node::AddChild(Node* pNode)
{
	m_pChildren.push_back(pNode);
}

/// <summary>
/// 全て初期化
/// </summary>
void MyLibrary::Node::InitializeAll()
{
	// 自身の初期化
	Initialize();

	// 子を初期化
	for (auto children : m_pChildren)
	{
		children->InitializeAll();
	}
}

/// <summary>
/// 全てを更新
/// </summary>
/// <param name="elapsedTime"></param>
void Node::UpdateAll(float elapsedTime)
{
	// 自身の更新
	Update(elapsedTime);

	// 子を更新
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->UpdateAll(elapsedTime);
		}
	}
}

/// <summary>
/// 全てを描画
/// </summary>
void Node::DrawAll()
{
	// 自信を描画
	Draw();

	// 子を描画
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->Draw();
		}
	}
}

/// <summary>
/// 自身の初期化処理
/// </summary>
void MyLibrary::Node::Initialize()
{
	;
}

/// <summary>
/// 自身の更新処理
/// </summary>
/// <param name="elapsedTime"></param>
void Node::Update(float elapsedTime)
{
	(void)elapsedTime;
}

/// <summary>
/// 自身の描画処理
/// </summary>
void Node::Draw()
{
	;
}
