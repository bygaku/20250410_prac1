#include "object_manager.hpp"


/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/
void ObjectManager::Update(const float& deltaTime)
{
	// 全てのオブジェクトを更新
	for (auto&& Objects : m_objects)
	{
		if (Objects.get() == nullptr)
		{
			continue;
		}

		Objects->Update(deltaTime);
	}

	// 無効なオブジェクトを全て削除
	RemoveUnAliveObjects();
}

void ObjectManager::Render()
{	
	// 全てのオブジェクトを描画
	for (auto&& Objects : m_objects)
	{
		if (Objects.get() == nullptr)
		{
			continue;
		}

		Objects->Render();
	}
}

void ObjectManager::AddObject(std::shared_ptr<Object> object)
{
	m_objects.emplace_back(object);
}

void ObjectManager::RemoveObject(std::string name)
{
	auto itr = m_ObjectItr.find(name.data());
	
	m_ObjectItr.erase(name);

	// 名前が登録されていない
	if (itr == m_ObjectItr.end())
	{
		return;
	}
}

/*===============================================================*\
 * ・プライベートメソッド
\*===============================================================*/

std::string ObjectManager::CreateObjectName(std::string baseName)
{
	std::string resultName;

	// 引数の名前のオブジェクトが既に存在しているか調べる
	auto itr = m_ObjectItr.find(baseName.data());
	bool isFirstName = false;

	// 初めての名前ならその名前のまま登録
	if (itr == m_ObjectItr.end())
	{
		isFirstName = true;
	}

	// 既に存在する名前なら, 名前が重複しないように番号を付ける
	for (size_t i = 1; true; ++i)
	{
		// 有効な名前を見つけたら終了
		if (isFirstName)
		{
			break;
		}

		// 新しい名前を作成
		resultName = baseName.data() + std::to_string(i);

		itr = m_ObjectItr.find(resultName);
		// 新しい名前のオブジェクトが存在しなければ
		if (itr == m_ObjectItr.end())
		{
			isFirstName = true;
		}
	}

	return resultName;

}

void ObjectManager::RemoveUnAliveObjects()
{
	for (auto itr = m_objects.begin(); itr != m_objects.end();)
	{
		// 無効なオブジェクトを削除
		if (itr->get() == nullptr || !itr->get()->IsAlive())
		{
			// オブジェクトのポインタが生きていたら
			if (itr->get() != nullptr)
			{
				// 名前とイテレータの情報を削除
				m_ObjectItr.erase(itr->get()->GetName().data());
			}

			// オブジェクトのインスタンスを削除
			itr = m_objects.erase(itr);
		}
		// 有効なオブジェクトなら何もせず次のオブジェクトを調べる
		else
		{
			itr++;
		}
	}
}
