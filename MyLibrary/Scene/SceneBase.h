//
// Scene.h
//
#pragma once

#include <string>

namespace MyLibrary
{
	namespace Scene
	{
		// クラス宣言
		class SceneManager;

		/// <summary>
		/// シーン基底クラス
		/// </summary>
		class SceneBase
		{
		public:

			// コンストラクタ
			SceneBase(SceneManager* pSceneManager, std::string name);

			// 仮想デストラクタ
			virtual ~SceneBase();

			// 初期化処理
			virtual void Initialize() = 0;

			// 更新処理
			virtual void Update(float elapsedTime) = 0;

			// 描画処理
			virtual void Render() = 0;

			// 終了処理
			virtual void Finalize() = 0;

			// 名前の取得
			std::string GetName();


		protected:

			// シーンマネージャーへのポインタ
			SceneManager* m_pScenemanager;

			// 名前
			std::string m_name;
		};
	}
}
