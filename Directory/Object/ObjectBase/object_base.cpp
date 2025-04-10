#include "object_base.hpp"

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

void Object::PreUpdate(const float& deltaTime)
{
	// 全てのコンポーネントのPreUpdateを呼ぶ
	for (auto&& itr : m_components)
	{
		if (itr == nullptr)
		{
			continue;
		}

		itr->PreUpdate(deltaTime);
	}
}

void Object::Update(const float& deltaTime)
{
	// 全てのコンポーネントのUpdateを呼ぶ
	for (auto&& itr : m_components)
	{
		if (itr == nullptr)
		{
			continue;
		}

		itr->Update(deltaTime);
	}
}

void Object::PostUpdate(const float& deltaTime)
{
	// 全てのコンポーネントのPostUpdateを呼ぶ
	for (auto&& itr : m_components)
	{
		if (itr == nullptr)
		{
			continue;
		}

		itr->PostUpdate(deltaTime);
	}
}

void Object::Render()
{	
	// 全てのコンポーネントのUpdateを呼ぶ
	for (auto&& itr : m_components)
	{
		if (itr == nullptr)
		{
			continue;
		}

		itr->Render();
	}
}

