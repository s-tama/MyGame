//
// Frag.h
//
#pragma once

namespace MyLibrary
{
	namespace Utility
	{
		/// <summary>
		/// フラグクラス
		/// </summary>
		class Flag
		{
		public:

			/// <summary>
			/// フラグのチェック
			/// </summary>
			/// <param name="flag"></param>
			/// <returns></returns>
			bool Check(unsigned char flag)
			{
				return ((m_flag & flag) != 0x00) ? true : false;
			}

			/// <summary>
			/// フラグをオンにする
			/// </summary>
			/// <param name="flag"></param>
			void On(unsigned char flag)
			{
				m_flag |= flag;
			}

			/// <summary>
			/// フラグをオフにする
			/// </summary>
			/// <param name="flag"></param>
			void Off(unsigned char flag)
			{
				m_flag &= ~flag;
			}


		private:

			// フラグ変数
			unsigned char m_flag = 0x00;
		};
	}
}
