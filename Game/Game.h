//
// Game.h
//

#pragma once

#include "../MyLibrary/MyLibrary.h"

/// <summary>
/// �Q�[���N���X
/// </summary>
class Game : public MyLibrary::Framework
{
public:

	// �R���X�g���N�^
	Game(HINSTANCE hInstance, int nCmdShow);

	// ����������
	void Initialize() override;

	// �I������
	void Finalize() override;


private:

	// �X�V����
	void Update(DX::StepTimer const& timer);

	// �`�揈��
	void Render();

	// �V�[���}�l�[�W���[
	std::unique_ptr<MyLibrary::Scene::SceneManager> m_pSceneManager;
};