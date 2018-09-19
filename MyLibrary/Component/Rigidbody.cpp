//
// Rigidbody.cpp
//

#include "../pch.h"
#include "Rigidbody.h"

#include "Transform.h"
#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
MyLibrary::Rigidbody::Rigidbody()
	: m_gravity(0.98f), m_velocity(Vector3::Zero)
{
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="elapsedTime"></param>
void MyLibrary::Rigidbody::Update(float elapsedTime)
{
	// �d�͂𑫂��Ă���
	m_velocity.y += m_gravity;

	// �X�V
	m_pTransform->SetPosition(
		m_pTransform->GetPosition() + m_velocity
	);
}
