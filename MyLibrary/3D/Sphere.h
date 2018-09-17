//
// Sphere.h
//
#pragma once

#include <GeometricPrimitive.h>

namespace MyLibrary
{
	/// <summary>
	/// ���N���X
	/// </summary>
	class Sphere
	{
	public:

		// �R���X�g���N�^
		Sphere(ID3D11DeviceContext* pContext, float size = 1.0f, size_t tessellation = 2);

		// �`��
		void Draw(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix projection);

		// �ʒu�̐ݒ�
		void SetPosition(DirectX::SimpleMath::Vector3 positon);
		void SetPosition(float x, float y, float z);

		// �ʒu�̎擾
		DirectX::SimpleMath::Vector3 GetPosition();

		// �N�I�[�^�j�I���̐ݒ�
		void SetRotation(DirectX::SimpleMath::Quaternion rotation);
		void SetRotation(float x, float y, float z, float w);

		// ��]�̎擾
		DirectX::SimpleMath::Quaternion GetRotation();

		// �F�̐ݒ�
		void SetColor(DirectX::FXMVECTOR color);

		// �T�C�Y�̐ݒ�
		void SetScale(float scale);

		// �T�C�Y�̎擾
		float GetScale();


	private:

		// �f�o�C�X�R���e�L�X�g
		ID3D11DeviceContext* m_pContext;

		// ��
		std::unique_ptr<DirectX::GeometricPrimitive> m_pSphere;

		// ���[���h�s��
		DirectX::SimpleMath::Matrix m_world;

		// �N�I�[�^�j�I��
		DirectX::SimpleMath::Quaternion m_rotation;

		// �F
		DirectX::SimpleMath::Vector4 m_color;

		// �ʒu
		DirectX::SimpleMath::Vector3 m_position;

		// ���x
		DirectX::SimpleMath::Vector3 m_velocity;

		// �T�C�Y
		float m_size;
	};
}
