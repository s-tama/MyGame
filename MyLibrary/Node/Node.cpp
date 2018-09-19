//
// Node.cpp
//

#include "Node.h"

#include "../Collision/Collision.h"
#include "../GameObject/GameObject.h"
#include "../Component/SphereCollider.h"

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
/// �S�Ă�������
/// </summary>
void MyLibrary::Node::InitializeAll()
{
	// ���M��������
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

			// ���Ƌ��̓����蔻��
			Collision::Sphere2Sphere(dynamic_cast<GameObject*>(this)->GetComponent<SphereCollider>(),
				dynamic_cast<GameObject*>(children)->GetComponent<SphereCollider>());
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
		children->DrawAll();
	}
}

/// <summary>
/// ����������
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
