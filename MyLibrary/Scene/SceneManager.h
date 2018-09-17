//
// SceneManager.h
//
#pragma once

#include <map>
#include <string>
#include <sstream>

namespace MyLibrary
{
	namespace Scene
	{
		// �N���X�錾
		class SceneBase;

		/// <summary>
		/// �V�[���Ǘ��N���X
		/// </summary>
		class SceneManager
		{
		public:

			// �R���X�g���N�^
			SceneManager();

			// �f�X�g���N�^
			~SceneManager();

			// �V�[���̓o�^
			void EntryScene(SceneBase* pEntryScene);

			// �J�n�V�[���̐ݒ�
			void StartScene(std::string sceneName);

			// �V�[����ύX
			void ChangeScene(std::string sceneName);

			// ���݂̃V�[�����X�V
			void UpdateActiveScene(float elapsedTime);

			// ���݂̃V�[����`��
			void RenderActiveScene();

			// �������̃V�[�����擾
			SceneBase* GetActiveScene();


		private:

			// �������̃V�[��
			SceneBase* m_pActiveScene;

			// �V�[���̃}�b�v
			std::map<std::string, SceneBase*> m_pSceneMap;
		};
	}
}
