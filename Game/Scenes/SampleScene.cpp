//
// SampleScene.cpp
//

#include "SampleScene.h"

using namespace MyLibrary;
using namespace MyLibrary::Scene;
using namespace MyGame;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="pSceneManager">�V�[���}�l�[�W���[�ւ̃|�C���^</param>
/// <param name="name">�V�[���̖��O</param>
SampleScene::SampleScene(SceneManager* pSceneManager)
	: SceneBase(pSceneManager, "SampleScene")
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SampleScene::~SampleScene()
{
}

/// <summary>
/// ����������
/// </summary>
void SampleScene::Initialize()
{
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="elapsedTime"></param>
void SampleScene::Update(float elapsedTime)
{
}

/// <summary>
/// �`�揈��
/// </summary>
void SampleScene::Render()
{
}

/// <summary>
/// �I������
/// </summary>
void SampleScene::Finalize()
{
}
