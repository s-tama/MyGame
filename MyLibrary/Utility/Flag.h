//
// Frag.h
//
#pragma once

namespace MyLibrary
{
	namespace Utility
	{
		/// <summary>
		/// �t���O�N���X
		/// </summary>
		class Flag
		{
		public:

			/// <summary>
			/// �t���O�̃`�F�b�N
			/// </summary>
			/// <param name="flag"></param>
			/// <returns></returns>
			bool Check(unsigned char flag)
			{
			}

			/// <summary>
			/// �t���O���I���ɂ���
			/// </summary>
			/// <param name="flag"></param>
			void On(unsigned char flag)
			{
			}

			/// <summary>
			/// �t���O���I�t�ɂ���
			/// </summary>
			/// <param name="flag"></param>
			void Off(unsigned char flag)
			{
			}


		private:

			// �t���O�ϐ�
			unsigned char m_flag = 0x00;
		};
	}
}
