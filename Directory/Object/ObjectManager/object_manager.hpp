#pragma once
#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"

/// @brief Objects管理クラス.
class ObjectManager
{
public:
	/// @brief コンストラクタ.
	ObjectManager() {};

	/// @brief 管理対象に追加するオブジェクト.
	void AddObject(std::shared_ptr<Object> object);

	/// @brief 管理対象から除外するオブジェクト.
	void RemoveObject(std::string name);

	/// @brief オブジェクトを作成して返す.
	template<typename ObjType>
	std::shared_ptr<Object> GenerateObject(std::string tag, std::string name)
	{
		// オブジェクトのインスタンスを作成
		std::shared_ptr<Object> newObject = std::make_shared<ObjType>(tag);

		// 生成するオブジェクトの名前を求める
		std::string objName = CreateObjectName(name);

		// オブジェクトに名前をセット
		newObject->SetName(objName);

		// オブジェクトを有効にする
		newObject->SetAlive(true);

		// オブジェクトをリストに追加, そのイテレータを取得
		m_objects.emplace_back(newObject);
		auto objectItr = std::prev(m_objects.end());

		// オブジェクトの名前とイテレータを紐づける
		m_ObjectItr[objName] = objectItr;

		return newObject;
	};

	#pragma region 推奨しない機能
	/// @brief 引数の名前のオブジェクトを作成して返す.
	/// @remark 同じ名前のオブジェクトが既に存在していた場合、名前の後ろに番号が付く
	std::shared_ptr<Object> CreateObject(std::string tag, std::string name) {};
	#pragma endregion

	/// @brief すべてのオブジェクトの更新, 除外管理.
	void Update(const float& deltaTime);

	/// @brief すべてのオブジェクトの描画.
	void Render();

private:
	/// @brief 引数の名前を元に被らない名前を作成.
	std::string CreateObjectName(std::string baseName);

	/// @brief 無効なオブジェクトを全て除外.
	void RemoveUnAliveObjects();

private:
	/// @brief オブジェクトの名称とイテレータを紐づけるコンテナ
	std::unordered_map
		<std::string, std::list<std::shared_ptr<Object>>::iterator> m_ObjectItr;

	/// @brief オブジェクトのインスタンスを格納するコンテナ
	std::list<std::shared_ptr<Object>> m_objects;

};