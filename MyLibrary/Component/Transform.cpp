//
// Transform.cpp
//

#include "Transform.h"

#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Transform::Transform()
	: m_position(Vector3::Zero), m_rotation(Vector3::Zero), m_scale(0.f), m_world(Matrix::Identity)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Transform::~Transform()
{
}

/// <summary>
/// �ړ�
/// </summary>
/// <param name="translate"></param>
void Transform::Translate(Vector3 translate)
{
	m_position += translate;
}

/// <summary>
/// �ړ�
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void Transform::Translate(float x, float y, float z)
{
	m_position.x += x;
	m_position.y += y;
	m_position.z += z;
}
