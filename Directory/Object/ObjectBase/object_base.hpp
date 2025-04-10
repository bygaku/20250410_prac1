#pragma once
#include "ipc.hpp"
#include "Component/component_base.hpp"

/*
/// @brief �I�u�W�F�N�g�̊��N���X.
/// @remark �R���|�[�l���g�̊Ǘ�
class Object
{
public:
	/// @brief �R���X�g���N�^.
	/// @param tag �I�u�W�F�N�g�̎�ޔ��ʃ^�O
	Object(std::string tag)
		: m_objPos	   (VGet(0.0f, 0.0f, 0.0f))
		, m_isAlive	   (true)
		, m_isVisible  (false)
		, m_objTag	   (tag)
	{
	};

	/// @brief �f�t�H���g�f�X�g���N�^.
	virtual ~Object() = default;

	/// @brief �R���|�[�l���g��ǉ�.
	template<typename CompType, typename...ArgTypes>
	auto AddComponent(const std::string tag, ArgTypes... args)
	{
		// �R���|�[�l���g�̃C���X�^���X���쐬
		std::shared_ptr<Component> setComponent 
			= std::make_shared<CompType>(tag, args...);

		// �R���|�[�l���g�̎�����Ƃ��Ă��̃I�u�W�F�N�g���Z�b�g
		setComponent->SetOwner(this);

		// �R���|�[�l���g�̃C���X�^���X���^�O�ƕR�Â����ĕۑ�
		m_components[tag] = setComponent;

		//return std::dynamic_pointer_cast<CompType>(setComponent);
	}

	template<typename CompType, typename...ArgTypes>
	auto GetComponent(const std::string tag)
	{
		auto itr = m_components.find(tag);

		// �����̖��O�̃R���|�[�l���g��������Ȃ�
		if (itr == m_components.end())
		{
			return;
		}

		return std::dynamic_pointer_cast<CompType>(m_components[tag]);
	}


	/// @brief �R���|�[�l���g��������폜����֐�.
	void RemoveComponent(const std::string tag);

	/// @brief �R���|�[�l���g�𖼑O����擾.
	// std::weak_ptr<Component> GetComponent(const std::string tag);

	/// @brief �I�u�W�F�N�g�̍X�V����.
	/// @param deltaTime FPS::GetDeltaTime();
	void Update(const float& deltaTime);

	/// @brief �I�u�W�F�N�g�̕`�揈��.
	void Render() {};

	#pragma region �I�u�W�F�N�g���A�N�Z�T.
	/// @brief �I�u�W�F�N�g�������̎擾.
	/// @return m_isAlive
	bool IsAlive() const { return m_isAlive; };

	// �I�u�W�F�N�g�̗L����Ԃ��Z�b�g.
	void SetAlive(bool isAlive) { m_isAlive = isAlive; };

	/// @brief �I�u�W�F�N�g�����̎擾.
	/// @return m_isVisible
	bool IsVisible() const { return m_isVisible; }; 

	/// @brief �I�u�W�F�N�g�̖��̂��擾.
	/// @return m_objName
	const std::string& GetName() const { return m_objName; };

	const VECTOR& GetPosition() const { return m_objPos; };

private:
	friend class ObjectManager;

	/// @brief �I�u�W�F�N�g�̖��̂��Z�b�g.
	void SetName(std::string name) { m_objName = name; };
	#pragma endregion

protected:
	VECTOR		m_objPos;		/// @brief ���W

	bool		m_isAlive;		/// @brief ��������
	bool		m_isVisible;	/// @brief ������

	std::string m_objTag;		/// @brief �I�u�W�F�N�g�̎��
	std::string m_objName;		/// @brief �I�u�W�F�N�g�̖���

private:
	std::unordered_map			/// @brief �^�O�ƃR���|�[�l���g���R�Â����ꂽ�R���e�i
		<std::string, std::shared_ptr<Component>> m_components;

};
*/

class Object : public std::enable_shared_from_this<Object>
{
public:	
	/// @brief �R���X�g���N�^.
	/// @param tag �I�u�W�F�N�g�̎�ޔ��ʃ^�O
	Object(std::string tag)
		: m_objTag   (tag)
		, m_objPos   (VGet(0.0f, 0.0f, 0.0f))
		, m_isAlive  (false)
		, m_isVisible(false)
	{
	};

	/// @brief �f�t�H���g�f�X�g���N�^.
	virtual ~Object() = default;

	/// @brief �I�u�W�F�N�g�̑O�X�V����.
	void PreUpdate(const float& deltaTime);

	/// @brief �I�u�W�F�N�g�̍X�V����.
	void Update(const float& deltaTime);

	/// @brief �I�u�W�F�N�g�̌�X�V����.
	void PostUpdate(const float& deltaTime);

	/// @brief �I�u�W�F�N�g�̕`��.
	void Render();
	
	/// @brief �R���|�[�l���g��ǉ�.
	template<typename CompType, typename...ArgTypes>
	[[nodiscard("Component")]] 
	std::shared_ptr<CompType> AddComponent(ArgTypes... args)
	{
		// �R���|�[�l���g�̃C���X�^���X���쐬
		std::shared_ptr<CompType> setComponent
			= std::make_shared<CompType>(shared_from_this(), args...);

		// �R���|�[�l���g�̃C���X�^���X���^�O�ƕR�Â����ĕۑ�
		m_components.emplace_back(setComponent);

		// �A�h���X��Ԃ�
		return setComponent;
	}

	/// @brief �R���|�[�l���g���擾.
	template<typename CompType>
	std::shared_ptr<CompType> GetComponent()
	{
		for (const auto& itr : m_components)
		{
			// dynamic_pointer_cast �Ō^�`�F�b�N���Ď擾
			if (auto casted = std::dynamic_pointer_cast<CompType>(itr))
			{				
				// �w�肳�ꂽ�R���|�[�l���g��Ԃ�
				return casted;
			}
		}

		// ������Ȃ�����
		return nullptr;
	}

	/// @brief �R���|�[�l���g��������폜����֐�.
	template<typename CompType>
	void RemoveComponent()
	{
		for (auto& itr : m_components)
		{
			if (auto casted = std::dynamic_pointer_cast<CompType>(itr))
			{
				// �R���|�[�l���g�̉���������Ă�
				casted->Exit();

				// �w�肳�ꂽ�R���|�[�l���g���폜
				m_components.erase(casted);
			}
		}

		// ������Ȃ�����
		return nullptr;
	}

	#pragma region �I�u�W�F�N�g���A�N�Z�T.
	/// @brief �I�u�W�F�N�g�������̎擾.
	/// @return m_isAlive
	bool IsAlive() const { return m_isAlive; };

	// �I�u�W�F�N�g�̗L����Ԃ��Z�b�g.
	void SetAlive(bool isAlive) { m_isAlive = isAlive; };

	/// @brief �I�u�W�F�N�g�����̎擾.
	/// @return m_isVisible
	bool IsVisible() const { return m_isVisible; };

	/// @brief �I�u�W�F�N�g�̖��̂��擾.
	/// @return m_objName
	const std::string& GetName() const { return m_objName; };

	/// @brief �I�u�W�F�N�g�̍��W���擾.
	/// @return m_objPos
	const VECTOR& GetPosition() const { return m_objPos; };

private:
	friend class ObjectManager;

	/// @brief �I�u�W�F�N�g�̖��̂��Z�b�g.
	void SetName(std::string name) { m_objName = name; };
	#pragma endregion

protected:
	VECTOR		m_objPos;		/// @brief ���W

	bool		m_isAlive;		/// @brief ��������
	bool		m_isVisible;	/// @brief ������

	std::string m_objTag;		/// @brief �I�u�W�F�N�g�̎��
	std::string m_objName;		/// @brief �I�u�W�F�N�g�̖���

private:
	/// @brief �R���|�[�l���g�R���e�i
	std::vector<std::shared_ptr<Component>> m_components;
};