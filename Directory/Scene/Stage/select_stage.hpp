#pragma once
#include "../SceneBase/scene_base.hpp"

/// @brief ステージセレクトシーンクラス.
/// @remark SceneManagerクラスで呼ばれます
class SelectScene : public SceneBase
{
public:
	/// @brief コンストラクタ.
	/// @param manager SceneManager の参照
	SelectScene(SceneManager& manager);

	/// @brief デストラクタ.
	virtual ~SelectScene() override;

	/// @brief セレクトシーン初期化.
	/// @remark リロードの時に一緒に初期化したいデータを入れる
	virtual void Initialise() override;

	/// @brief セレクトシーン更新.
	virtual void Update(const float& deltaTime) override;

	/// @brief セレクトシーン描画.
	virtual void Render() const override;

	/// @brief カウントアップタイマーをセット.
	virtual void UpdateTimer(const float& deltaTime) override;

private:
	/// @brief シーンの[後始末]の条件式.
	virtual void SceneFinaliseCondition() override;


};
