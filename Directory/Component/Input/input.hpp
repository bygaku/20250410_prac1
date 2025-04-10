#pragma once
#include "Component/component_base.hpp"

class InputComponent : public Component
{
public:
	/// @brief コンストラクタ
	InputComponent(std::weak_ptr<Object> object);

	/// @brief デフォルトデストラクタ
	virtual ~InputComponent() override = default;

	/// @brief InputPlayer前更新処理
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief InputPlayer更新処理
	virtual void Update(const float& deltaTime) override;

	/// @brief InputPlayer後更新処理
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief InputPlayer描画処理
	virtual void Render() override {};

	/// @brief InputPlayer解放処理
	virtual void Exit() override {};

	#pragma region 外部に公開する入力状態

	/// @brief 左スティック傾けXの量
	float GetLeftHorizontal() const { return m_LX; };
	/// @brief 左スティック傾けYの量
	float GetLeftVertical() const { return m_LY; };


	/// @brief 右スティック傾けXの量
	float GetRightHorizontal() const { return m_RX; };
	/// @brief 右スティック傾けYの量
	float GetRightVertical() const { return m_RY; };

#pragma endregion
private:
	/// デッドゾーン処理
	float ApplyDeadZone(float value) const;

private:
	float m_LX;
	float m_LY;
	float m_RX;
	float m_RY;

	const float k_deadZone	= 0.3f;

};
