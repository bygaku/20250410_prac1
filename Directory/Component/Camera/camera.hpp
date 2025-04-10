#pragma once
#include "Component/component_base.hpp"

class CameraComponent : public Component
{
public:
	CameraComponent(std::weak_ptr<Object> object);

	virtual ~CameraComponent() override = default;

	/// @brief カメラ前更新処理.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief カメラ更新処理.
	virtual void Update(const float& deltaTime) override;

	/// @brief カメラ後更新処理.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief カメラ描画処理.
	virtual void Render() override {};

	/// @brief カメラ解放処理.
	virtual void Exit() override {};

	/// @brief オフセット値を設定.
	void SetOffset(const VECTOR& offset);
private:
	const float k_near;				/// @brief 最少描画距離
	const float k_far;				/// @brief 最大描画距離
	const float k_Speed;
	VECTOR m_lookPos;
	VECTOR m_movePos;
	VECTOR m_offset;				/// @brief カメラのオフセット値
};


