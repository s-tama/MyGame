//
// SampleScene.h
//
#pragma once

#include "../../MyLibrary/MyLibrary.h"

namespace MyGame
{
	/// <summary>
	/// �T���v���V�[��
	/// </summary>
	class SampleScene : public MyLibrary::Scene::SceneBase
	{
	public:

		// �R���X�g���N�^
		SampleScene(MyLibrary::Scene::SceneManager* pSceneManager);

		// �f�X�g���N�^
		~SampleScene();

		// ����������
		void Initialize() override;

		// �X�V����
		void Update(float elapsedTime) override;

		// �`�揈��
		void Render() override;

		// �I������
		void Finalize() override;
	};
}
