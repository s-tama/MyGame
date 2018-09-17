//
// Sphere.cpp
//

#include "../pch.h"
#include "Sphere.h"

using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="context"></param>
/// <param name="size"></param>
/// <param name="tessellation"></param>
MyLibrary::Sphere::Sphere(ID3D11DeviceContext * pContext, float size, size_t tessellation)
	: m_world(Matrix::Identity), m_color(Colors::White), m_position(Vector3::Zero), m_velocity(Vector3::Zero), m_size(1.0f), m_rotation(Quaternion::Identity)
{
	// ���̍쐬
	m_pSphere = GeometricPrimitive::CreateGeoSphere(pContext, size, tessellation, false);
}

/// <summary>
/// �`��
/// </summary>
/// <param name="view">�r���[�s��</param>
/// <param name="projection">�ˉe�s��</param>
void MyLibrary::Sphere::Draw(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix projection)
{
	// ���[���h�s��̍쐬
	Matrix trans = Matrix::CreateTranslation(m_position);
	Matrix scale = Matrix::CreateScale(m_size);
	Matrix rot = Matrix::CreateFromQuaternion(m_rotation);
	m_world = scale * rot * trans;

	// ���̕`��
	m_pSphere->Draw(m_world, view, projection, m_color, nullptr, true);
}

/// <summary>
/// �ʒu�̐ݒ�
/// </summary>
/// <param name="positon">���W</param>
void MyLibrary::Sphere::SetPosition(DirectX::SimpleMath::Vector3 positon)
{
	m_position = positon;
}

/// <summary>
/// �ʒu�̐ݒ�
/// </summary>
/// <param name="x">x</param>
/// <param name="y">y</param>
/// <param name="z">z</param>
void MyLibrary::Sphere::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

/// <summary>
/// ���W�̎擾
/// </summary>
/// <returns></returns>
DirectX::SimpleMath::Vector3 MyLibrary::Sphere::GetPosition()
{
	return m_position;
}

/// <summary>
/// ��]�̐ݒ�
/// </summary>
/// <param name="rotation"></param>
void MyLibrary::Sphere::SetRotation(DirectX::SimpleMath::Quaternion rotation)
{
	m_rotation = rotation;
}

/// <summary>
/// ��]�̐ݒ�
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <param name="w"></param>
void MyLibrary::Sphere::SetRotation(float x, float y, float z, float w)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
	m_rotation.w = w;
}

/// <summary>
/// ��]�̎擾
/// </summary>
/// <returns></returns>
DirectX::SimpleMath::Quaternion MyLibrary::Sphere::GetRotation()
{
	return m_rotation;
}

/// <summary>
/// �F�̐ݒ�
/// </summary>
/// <param name="color"></param>
void MyLibrary::Sphere::SetColor(DirectX::FXMVECTOR color)
{
	m_color = color;
}

/// <summary>
/// �傫���̐ݒ�
/// </summary>
/// <param name="scale"></param>
void MyLibrary::Sphere::SetScale(float scale)
{
	m_size = scale;
}

/// <summary>
/// �傫���̎擾
/// </summary>
/// <returns></returns>
float MyLibrary::Sphere::GetScale()
{
	return m_size;
}