//
// Node.cpp
//

#include "Node.h"

using namespace MyLibrary;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Node::Node()
{
}

/// <summary>
/// ���z�f�X�g���N�^
/// </summary>
Node::~Node()
{
}

/// <summary>
/// �q��ǉ�
/// </summary>
/// <param name="pNode">�m�[�h</param>
void Node::AddChild(Node* pNode)
{
	m_pChildren.push_back(pNode);
}

/// <summary>
/// �S�ď�����
/// </summary>
void MyLibrary::Node::InitializeAll()
{
	// ���g�̏�����
	Initialize();

	// �q��������
	for (auto children : m_pChildren)
	{
		children->InitializeAll();
	}
}

/// <summary>
/// �S�Ă��X�V
/// </summary>
/// <param name="elapsedTime"></param>
void Node::UpdateAll(float elapsedTime)
{
	// ���g�̍X�V
	Update(elapsedTime);

	// �q���X�V
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->UpdateAll(elapsedTime);
		}
	}
}

/// <summary>
/// �S�Ă�`��
/// </summary>
void Node::DrawAll()
{
	// ���M��`��
	Draw();

	// �q��`��
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->Draw();
		}
	}
}

/// <summary>
/// ���g�̏���������
/// </summary>
void MyLibrary::Node::Initialize()
{
	;
}

/// <summary>
/// ���g�̍X�V����
/// </summary>
/// <param name="elapsedTime"></param>
void Node::Update(float elapsedTime)
{
	(void)elapsedTime;
}

/// <summary>
/// ���g�̕`�揈��
/// </summary>
void Node::Draw()
{
	;
}
