//
// Transform.h
//
#pragma once

#include "../pch.h"
#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// �g�����X�t�H�[���N���X
	/// </summary>
	class Transform : public Component
	{
	public:

		// �R���X�g���N�^
		Transform();

		// �f�X�g���N�^
		~Transform();

		// �ړ�
		void Translate(DirectX::SimpleMath::Vector3 translate);
		void Translate(float x, float y, float z);

		// ���[���h�s��̎擾
		DirectX::SimpleMath::Matrix GetWorld() { return m_world; }
		// ���[���h�s��̐ݒ�
		void SetWorld(DirectX::SimpleMath::Matrix world) { m_world = world; }

		// ���W���擾
		DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }
		// ���W��ݒ�
		void SetPosition(DirectX::SimpleMath::Vector3 position) { m_position = position; }
		void SetPosition(float x, float y, float z) { m_position = DirectX::SimpleMath::Vector3(x, y, z); }

		// �X�P�[�����擾
		DirectX::SimpleMath::Vector3 GetScale() { return m_scale; }
		// �X�P�[����ݒ�
		void SetScale(DirectX::SimpleMath::Vector3 scale) { m_scale = scale; }
		void SetScale(float x, float y, float z) { m_scale = DirectX::SimpleMath::Vector3(x, y, z); }

		// ��]���擾
		DirectX::SimpleMath::Quaternion GetRotation() { return m_rotation; }


	private:

		// ���W
		DirectX::SimpleMath::Vector3 m_position;

		// �X�P�[��
		DirectX::SimpleMath::Vector3 m_scale;

		// ��]
		DirectX::SimpleMath::Quaternion m_rotation;

		// ���[���h�s��
		DirectX::SimpleMath::Matrix m_world;
	};
}