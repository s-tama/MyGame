//
// Player.cpp
//

#include "Player.h"

using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
	: GameObject("Player")
{
}

/// <summary>
/// ����������
/// </summary>
void Player::Initialize()
{
	// ���W�b�h�{�f�B��ǉ�
	this->AddComponent<Rigidbody>();

	// �X�t�B�A�R���C�_��ǉ�
	this->AddComponent<SphereCollider>();
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="elapsedTime">�o�ߎ���</param>
void Player::Update(float elapsedTime)
{
	// ���W�b�h�{�f�B�X�V
	this->GetComponent<Rigidbody>()->Update(elapsedTime);
}

/// <summary>
/// �`�揈��
/// </summary>
void Player::Draw()
{
}
