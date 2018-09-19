//
// Node.h
//
#pragma once

#include <list>

namespace MyLibrary
{
	/// <summary>
	/// �Q�[���I�u�W�F�N�g�Ǘ��m�[�h�N���X
	/// </summary>
	class Node
	{
	public:

		// �R���X�g���N�^
		Node();

		// ���z�f�X�g���N�^
		virtual ~Node();

		// �q��ǉ�
		void AddChild(Node* pNode);

		// ����������
		void InitializeAll();

		// �X�V����
		void UpdateAll(float elapsedTime);

		// �`�悷��
		void DrawAll();

		
	private:

		// ���g�̏���������
		virtual void Initialize();

		// ���g�̍X�V����
		virtual void Update(float elapsedTime);

		// ���g�̕`�揈��
		virtual void Draw();


	private:

		// �q�m�[�h
		std::list<Node*> m_pChildren;
	};
}
