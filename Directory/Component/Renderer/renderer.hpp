#pragma once
#include "Component/component_base.hpp"

class RendererComponent : public Component
{
public:
	/// @brief コンストラクタ.
	RendererComponent(std::weak_ptr<Object> object);

	/// @brief デフォルトデストラクタ.
	virtual ~RendererComponent() override = default;

	/// @brief Renderer前更新処理.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Renderer更新処理.
	virtual void Update(const float& deltaTime) override;

	/// @brief Renderer後更新処理.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Renderer描画処理.
	virtual void Render() override;

	/// @brief Renderer解放処理.
	virtual void Exit() override {};
};
