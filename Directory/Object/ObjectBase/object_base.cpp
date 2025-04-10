#include "object_base.hpp"

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

void Object::PreUpdate(const float& deltaTime)
{
	// �S�ẴR���|�[�l���g��PreUpdate���Ă�
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
	// �S�ẴR���|�[�l���g��Update���Ă�
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
	// �S�ẴR���|�[�l���g��PostUpdate���Ă�
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
	// �S�ẴR���|�[�l���g��Update���Ă�
	for (auto&& itr : m_components)
	{
		if (itr == nullptr)
		{
			continue;
		}

		itr->Render();
	}
}

