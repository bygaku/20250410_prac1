#pragma once
#include "Component/component_base.hpp"

class TransformComponent : public Component
{
public:
	/// @brief コンストラクタ.
	TransformComponent(std::weak_ptr<Object> object/*, const float& scale*/);

	/// @brief デフォルトデストラクタ.
	virtual ~TransformComponent() override = default;

	/// @brief Transform前更新処理.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Transform更新処理.
	virtual void Update(const float& deltaTime) override;

	/// @brief Transform後更新処理.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Transform描画処理.
	virtual void Render() override {};

	/// @brief Transform解放処理.
	virtual void Exit() override {};

	/// @brief ワールド座標の取得.
	//const VECTOR& GetWorldPosition() const { return m_objWorldPos; };

	/// @brief 座標の取得.
	const VECTOR& GetPosition() const { return m_objPos; };

	/// @brief 回転の取得.
	const VECTOR& GetRotation() const { return m_objRota; };

	/// @brief サイズの取得.
	const VECTOR& GetScale() const { return m_objScale; };

	VECTOR	m_objPos;			/// @brief 座標
protected:
	/// @brief オブジェクトの座標を算出.
	void CalcObjPos() { m_objPos = VAdd(m_objWorldPos, m_objLocalPos); };

private:
	VECTOR	m_objWorldPos;		/// @brief ワールド座標
	VECTOR	m_objLocalPos;		/// @brief ローカル座標
	VECTOR	m_objRota;			/// @brief 回転
	VECTOR	m_objScale;			/// @brief オブジェクトの大きさ
};
