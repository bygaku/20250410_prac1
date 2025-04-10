#pragma once
#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"

/// @brief Objects�Ǘ��N���X.
class ObjectManager
{
public:
	/// @brief �R���X�g���N�^.
	ObjectManager() {};

	/// @brief �Ǘ��Ώۂɒǉ�����I�u�W�F�N�g.
	void AddObject(std::shared_ptr<Object> object);

	/// @brief �Ǘ��Ώۂ��珜�O����I�u�W�F�N�g.
	void RemoveObject(std::string name);

	/// @brief �I�u�W�F�N�g���쐬���ĕԂ�.
	template<typename ObjType>
	std::shared_ptr<Object> GenerateObject(std::string tag, std::string name)
	{
		// �I�u�W�F�N�g�̃C���X�^���X���쐬
		std::shared_ptr<Object> newObject = std::make_shared<ObjType>(tag);

		// ��������I�u�W�F�N�g�̖��O�����߂�
		std::string objName = CreateObjectName(name);

		// �I�u�W�F�N�g�ɖ��O���Z�b�g
		newObject->SetName(objName);

		// �I�u�W�F�N�g��L���ɂ���
		newObject->SetAlive(true);

		// �I�u�W�F�N�g�����X�g�ɒǉ�, ���̃C�e���[�^���擾
		m_objects.emplace_back(newObject);
		auto objectItr = std::prev(m_objects.end());

		// �I�u�W�F�N�g�̖��O�ƃC�e���[�^��R�Â���
		m_ObjectItr[objName] = objectItr;

		return newObject;
	};

	#pragma region �������Ȃ��@�\
	/// @brief �����̖��O�̃I�u�W�F�N�g���쐬���ĕԂ�.
	/// @remark �������O�̃I�u�W�F�N�g�����ɑ��݂��Ă����ꍇ�A���O�̌��ɔԍ����t��
	std::shared_ptr<Object> CreateObject(std::string tag, std::string name) {};
	#pragma endregion

	/// @brief ���ׂẴI�u�W�F�N�g�̍X�V, ���O�Ǘ�.
	void Update(const float& deltaTime);

	/// @brief ���ׂẴI�u�W�F�N�g�̕`��.
	void Render();

private:
	/// @brief �����̖��O�����ɔ��Ȃ����O���쐬.
	std::string CreateObjectName(std::string baseName);

	/// @brief �����ȃI�u�W�F�N�g��S�ď��O.
	void RemoveUnAliveObjects();

private:
	/// @brief �I�u�W�F�N�g�̖��̂ƃC�e���[�^��R�Â���R���e�i
	std::unordered_map
		<std::string, std::list<std::shared_ptr<Object>>::iterator> m_ObjectItr;

	/// @brief �I�u�W�F�N�g�̃C���X�^���X���i�[����R���e�i
	std::list<std::shared_ptr<Object>> m_objects;

};