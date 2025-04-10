#pragma once
#include "ipc.hpp"

class Object;

/// @brief コンポーネント基底クラス.
class Component
{
public:
	/// @brief コンストラクタ.
	Component(std::weak_ptr<Object> object)
		: m_owner(object)
	{
	};

	/// @brief デフォルトデストラクタ.
	virtual ~Component() = default;

	/// @brief 前更新処理.
	virtual void PreUpdate(const float& deltaTime) = 0;

	/// @brief メイン更新処理.
	virtual void Update(const float& deltaTime) = 0;

	/// @brief 後更新処理.
	virtual void PostUpdate(const float& deltaTime) = 0;

	/// @brief 描画処理.
	virtual void Render() = 0;

	/// @brief 解放処理.
	virtual void Exit() = 0;

	/// @brief 
	std::weak_ptr<Object> GetOwner() { return m_owner; };

	/// @brief このコンポーネントを所持するオブジェクトをセット.
	/// @param ownerName オブジェクト ( this参照 )
	//void SetOwner(std::weak_ptr<Object> ownerName) { m_owner = ownerName; };

private:
	std::weak_ptr<Object>	m_owner;	/// @brief コンポーネントの所持参照

};


/// プレイヤーについて
/// ・プレイヤーの状態（基底クラスのゲームオブジェクトごと引数として渡す）を各コンポーネントに渡してあげる必要がありそう。
/// ・プレイヤーは現在走っています。=> GraphicsComponentは走っているを描画する。
/// 
/// コンポーネント
/// ・Transform
/// ・Physics
/// ・Rendering
/// ・Input
