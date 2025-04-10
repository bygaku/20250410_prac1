#pragma once
#include "ipc.hpp"
#include "Component/component_base.hpp"

/*
/// @brief オブジェクトの基底クラス.
/// @remark コンポーネントの管理
class Object
{
public:
	/// @brief コンストラクタ.
	/// @param tag オブジェクトの種類判別タグ
	Object(std::string tag)
		: m_objPos	   (VGet(0.0f, 0.0f, 0.0f))
		, m_isAlive	   (true)
		, m_isVisible  (false)
		, m_objTag	   (tag)
	{
	};

	/// @brief デフォルトデストラクタ.
	virtual ~Object() = default;

	/// @brief コンポーネントを追加.
	template<typename CompType, typename...ArgTypes>
	auto AddComponent(const std::string tag, ArgTypes... args)
	{
		// コンポーネントのインスタンスを作成
		std::shared_ptr<Component> setComponent 
			= std::make_shared<CompType>(tag, args...);

		// コンポーネントの持ち主としてこのオブジェクトをセット
		setComponent->SetOwner(this);

		// コンポーネントのインスタンスをタグと紐づけして保存
		m_components[tag] = setComponent;

		//return std::dynamic_pointer_cast<CompType>(setComponent);
	}

	template<typename CompType, typename...ArgTypes>
	auto GetComponent(const std::string tag)
	{
		auto itr = m_components.find(tag);

		// 引数の名前のコンポーネントが見つからない
		if (itr == m_components.end())
		{
			return;
		}

		return std::dynamic_pointer_cast<CompType>(m_components[tag]);
	}


	/// @brief コンポーネントを解放し削除する関数.
	void RemoveComponent(const std::string tag);

	/// @brief コンポーネントを名前から取得.
	// std::weak_ptr<Component> GetComponent(const std::string tag);

	/// @brief オブジェクトの更新処理.
	/// @param deltaTime FPS::GetDeltaTime();
	void Update(const float& deltaTime);

	/// @brief オブジェクトの描画処理.
	void Render() {};

	#pragma region オブジェクト情報アクセサ.
	/// @brief オブジェクト生死情報の取得.
	/// @return m_isAlive
	bool IsAlive() const { return m_isAlive; };

	// オブジェクトの有効状態をセット.
	void SetAlive(bool isAlive) { m_isAlive = isAlive; };

	/// @brief オブジェクト可視情報の取得.
	/// @return m_isVisible
	bool IsVisible() const { return m_isVisible; }; 

	/// @brief オブジェクトの名称を取得.
	/// @return m_objName
	const std::string& GetName() const { return m_objName; };

	const VECTOR& GetPosition() const { return m_objPos; };

private:
	friend class ObjectManager;

	/// @brief オブジェクトの名称をセット.
	void SetName(std::string name) { m_objName = name; };
	#pragma endregion

protected:
	VECTOR		m_objPos;		/// @brief 座標

	bool		m_isAlive;		/// @brief 生死判定
	bool		m_isVisible;	/// @brief 可視判定

	std::string m_objTag;		/// @brief オブジェクトの種類
	std::string m_objName;		/// @brief オブジェクトの名称

private:
	std::unordered_map			/// @brief タグとコンポーネントが紐づけされたコンテナ
		<std::string, std::shared_ptr<Component>> m_components;

};
*/

class Object : public std::enable_shared_from_this<Object>
{
public:	
	/// @brief コンストラクタ.
	/// @param tag オブジェクトの種類判別タグ
	Object(std::string tag)
		: m_objTag   (tag)
		, m_objPos   (VGet(0.0f, 0.0f, 0.0f))
		, m_isAlive  (false)
		, m_isVisible(false)
	{
	};

	/// @brief デフォルトデストラクタ.
	virtual ~Object() = default;

	/// @brief オブジェクトの前更新処理.
	void PreUpdate(const float& deltaTime);

	/// @brief オブジェクトの更新処理.
	void Update(const float& deltaTime);

	/// @brief オブジェクトの後更新処理.
	void PostUpdate(const float& deltaTime);

	/// @brief オブジェクトの描画.
	void Render();
	
	/// @brief コンポーネントを追加.
	template<typename CompType, typename...ArgTypes>
	[[nodiscard("Component")]] 
	std::shared_ptr<CompType> AddComponent(ArgTypes... args)
	{
		// コンポーネントのインスタンスを作成
		std::shared_ptr<CompType> setComponent
			= std::make_shared<CompType>(shared_from_this(), args...);

		// コンポーネントのインスタンスをタグと紐づけして保存
		m_components.emplace_back(setComponent);

		// アドレスを返す
		return setComponent;
	}

	/// @brief コンポーネントを取得.
	template<typename CompType>
	std::shared_ptr<CompType> GetComponent()
	{
		for (const auto& itr : m_components)
		{
			// dynamic_pointer_cast で型チェックして取得
			if (auto casted = std::dynamic_pointer_cast<CompType>(itr))
			{				
				// 指定されたコンポーネントを返す
				return casted;
			}
		}

		// 見つからなかった
		return nullptr;
	}

	/// @brief コンポーネントを解放し削除する関数.
	template<typename CompType>
	void RemoveComponent()
	{
		for (auto& itr : m_components)
		{
			if (auto casted = std::dynamic_pointer_cast<CompType>(itr))
			{
				// コンポーネントの解放処理を呼ぶ
				casted->Exit();

				// 指定されたコンポーネントを削除
				m_components.erase(casted);
			}
		}

		// 見つからなかった
		return nullptr;
	}

	#pragma region オブジェクト情報アクセサ.
	/// @brief オブジェクト生死情報の取得.
	/// @return m_isAlive
	bool IsAlive() const { return m_isAlive; };

	// オブジェクトの有効状態をセット.
	void SetAlive(bool isAlive) { m_isAlive = isAlive; };

	/// @brief オブジェクト可視情報の取得.
	/// @return m_isVisible
	bool IsVisible() const { return m_isVisible; };

	/// @brief オブジェクトの名称を取得.
	/// @return m_objName
	const std::string& GetName() const { return m_objName; };

	/// @brief オブジェクトの座標を取得.
	/// @return m_objPos
	const VECTOR& GetPosition() const { return m_objPos; };

private:
	friend class ObjectManager;

	/// @brief オブジェクトの名称をセット.
	void SetName(std::string name) { m_objName = name; };
	#pragma endregion

protected:
	VECTOR		m_objPos;		/// @brief 座標

	bool		m_isAlive;		/// @brief 生死判定
	bool		m_isVisible;	/// @brief 可視判定

	std::string m_objTag;		/// @brief オブジェクトの種類
	std::string m_objName;		/// @brief オブジェクトの名称

private:
	/// @brief コンポーネントコンテナ
	std::vector<std::shared_ptr<Component>> m_components;
};