#pragma once
#include "Component/component_base.hpp"

class ModelComponent : public Component
{
public:
	/// @brief コンストラクタ.
	ModelComponent(std::weak_ptr<Object> object);

	/// @brief デストラクタ.
	virtual ~ModelComponent() override;

	/// @brief Model前更新処理.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Model更新処理.
	virtual void Update(const float& deltaTime) override;

	/// @brief Model後更新処理.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Model描画処理.
	virtual void Render() override;

	/// @brief Model解放処理.
	virtual void Exit() override {};

	/// @brief モデルの読み込み.
	/// @param filePath ファイル名
	bool LoadModel(const std::string& filePath);

	/// @brief 可視を設定.
	void SetVisible(bool visible) { m_visible = visible; };

	/// @brief サイズを設定.
	/// @param scale float 1.0f = 通常のサイズ
	void SetScale(float scale) { m_scale = scale; };

	/// @brief 回転を設定.
	/// @param rotation VECTOR { x, y , z }
	void SetRotation(const VECTOR& rotation) { m_rota = rotation; };

	/// @brief 3Dモデルハンドルの取得.
	int GetModelHandle() const { return m_modelHandle; }

private:
	int		m_modelHandle;
	bool	m_visible;
	float	m_scale;
	VECTOR	m_rota;

};
