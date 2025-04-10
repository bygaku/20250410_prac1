#include "object_manager.hpp"


/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/
void ObjectManager::Update(const float& deltaTime)
{
	// �S�ẴI�u�W�F�N�g���X�V
	for (auto&& Objects : m_objects)
	{
		if (Objects.get() == nullptr)
		{
			continue;
		}

		Objects->Update(deltaTime);
	}

	// �����ȃI�u�W�F�N�g��S�č폜
	RemoveUnAliveObjects();
}

void ObjectManager::Render()
{	
	// �S�ẴI�u�W�F�N�g��`��
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

	// ���O���o�^����Ă��Ȃ�
	if (itr == m_ObjectItr.end())
	{
		return;
	}
}

/*===============================================================*\
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/

std::string ObjectManager::CreateObjectName(std::string baseName)
{
	std::string resultName;

	// �����̖��O�̃I�u�W�F�N�g�����ɑ��݂��Ă��邩���ׂ�
	auto itr = m_ObjectItr.find(baseName.data());
	bool isFirstName = false;

	// ���߂Ă̖��O�Ȃ炻�̖��O�̂܂ܓo�^
	if (itr == m_ObjectItr.end())
	{
		isFirstName = true;
	}

	// ���ɑ��݂��閼�O�Ȃ�, ���O���d�����Ȃ��悤�ɔԍ���t����
	for (size_t i = 1; true; ++i)
	{
		// �L���Ȗ��O����������I��
		if (isFirstName)
		{
			break;
		}

		// �V�������O���쐬
		resultName = baseName.data() + std::to_string(i);

		itr = m_ObjectItr.find(resultName);
		// �V�������O�̃I�u�W�F�N�g�����݂��Ȃ����
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
		// �����ȃI�u�W�F�N�g���폜
		if (itr->get() == nullptr || !itr->get()->IsAlive())
		{
			// �I�u�W�F�N�g�̃|�C���^�������Ă�����
			if (itr->get() != nullptr)
			{
				// ���O�ƃC�e���[�^�̏����폜
				m_ObjectItr.erase(itr->get()->GetName().data());
			}

			// �I�u�W�F�N�g�̃C���X�^���X���폜
			itr = m_objects.erase(itr);
		}
		// �L���ȃI�u�W�F�N�g�Ȃ牽���������̃I�u�W�F�N�g�𒲂ׂ�
		else
		{
			itr++;
		}
	}
}
