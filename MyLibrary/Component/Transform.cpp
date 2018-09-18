//
// Transform.cpp
//

#include "../pch.h"
#include "Transform.h"

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
