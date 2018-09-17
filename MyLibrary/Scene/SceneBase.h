//
// Scene.h
//
#pragma once

#include <string>

namespace MyLibrary
{
	namespace Scene
	{
		// �N���X�錾
		class SceneManager;

		/// <summary>
		/// �V�[�����N���X
		/// </summary>
		class SceneBase
		{
		public:

			// �R���X�g���N�^
			SceneBase(SceneManager* pSceneManager, std::string name);

			// ���z�f�X�g���N�^
			virtual ~SceneBase();

			// ����������
			virtual void Initialize() = 0;

			// �X�V����
			virtual void Update(float elapsedTime) = 0;

			// �`�揈��
			virtual void Render() = 0;

			// �I������
			virtual void Finalize() = 0;

			// ���O�̎擾
			std::string GetName();


		protected:

			// �V�[���}�l�[�W���[�ւ̃|�C���^
			SceneManager* m_pScenemanager;

			// ���O
			std::string m_name;
		};
	}
}
