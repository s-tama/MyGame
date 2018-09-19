//
// Component.h
//
#pragma once

namespace MyLibrary
{
	// �N���X�錾
	class Transform;
	class GameObject;

	/// <summary>
	/// �R���|�[�l���g�N���X
	/// </summary>
	class Component
	{
	public:

		// �R���X�g���N�^
		Component();

		// ���z�f�X�g���N�^
		virtual ~Component();

		// �Q�[���I�u�W�F�N�g�̎擾
		GameObject* GetGameObject();
		// �Q�[���I�u�W�F�N�g�̐ݒ�
		void SetGameObject(GameObject* pGameObject);

		// �g�����X�t�H�[���̎擾
		Transform* GetTransform();
		// �g�����X�t�H�[���̐ݒ�
		void SetTransform(Transform* pTransform);


	protected:

		// �g�����X�t�H�[���ւ̃|�C���^
		Transform* m_pTransform;

		// �Q�[���I�u�W�F�N�g�ւ̃|�C���^
		GameObject* m_pGameObject;
	};
}
