//
// SphereCollider.cpp
//

#include "../pch.h"
#include "SphereCollider.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SphereCollider::SphereCollider()
	: m_radius(0.f), m_center(Vector3::Zero)
{
}

/// <summary>
/// �R�s�[�R���X�g���N�^
/// </summary>
/// <param name="center"></param>
/// <param name="radius"></param>
SphereCollider::SphereCollider(DirectX::SimpleMath::Vector3 center, float radius)
	: m_center(center), m_radius(radius)
{
}
