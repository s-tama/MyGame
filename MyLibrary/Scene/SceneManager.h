//
// SceneManager.h
//
#pragma once

#include <map>
#include <string>
#include <sstream>

namespace MyLibrary
{
	namespace Scene
	{
		// クラス宣言
		class SceneBase;

		/// <summary>
		/// シーン管理クラス
		/// </summary>
		class SceneManager
		{
		public:

			// コンストラクタ
			SceneManager();

			// デストラクタ
			~SceneManager();

			// シーンの登録
			void EntryScene(SceneBase* pEntryScene);

			// 開始シーンの設定
			void StartScene(std::string sceneName);

			// シーンを変更
			void ChangeScene(std::string sceneName);

			// 現在のシーンを更新
			void UpdateActiveScene(float elapsedTime);

			// 現在のシーンを描画
			void RenderActiveScene();

			// 活動中のシーンを取得
			SceneBase* GetActiveScene();


		private:

			// 活動中のシーン
			SceneBase* m_pActiveScene;

			// シーンのマップ
			std::map<std::string, SceneBase*> m_pSceneMap;
		};
	}
}
