#pragma once
#include "ipc.hpp"

class Object;

/// @brief �R���|�[�l���g���N���X.
class Component
{
public:
	/// @brief �R���X�g���N�^.
	Component(std::weak_ptr<Object> object)
		: m_owner(object)
	{
	};

	/// @brief �f�t�H���g�f�X�g���N�^.
	virtual ~Component() = default;

	/// @brief �O�X�V����.
	virtual void PreUpdate(const float& deltaTime) = 0;

	/// @brief ���C���X�V����.
	virtual void Update(const float& deltaTime) = 0;

	/// @brief ��X�V����.
	virtual void PostUpdate(const float& deltaTime) = 0;

	/// @brief �`�揈��.
	virtual void Render() = 0;

	/// @brief �������.
	virtual void Exit() = 0;

	/// @brief 
	std::weak_ptr<Object> GetOwner() { return m_owner; };

	/// @brief ���̃R���|�[�l���g����������I�u�W�F�N�g���Z�b�g.
	/// @param ownerName �I�u�W�F�N�g ( this�Q�� )
	//void SetOwner(std::weak_ptr<Object> ownerName) { m_owner = ownerName; };

private:
	std::weak_ptr<Object>	m_owner;	/// @brief �R���|�[�l���g�̏����Q��

};


/// �v���C���[�ɂ���
/// �E�v���C���[�̏�ԁi���N���X�̃Q�[���I�u�W�F�N�g���ƈ����Ƃ��ēn���j���e�R���|�[�l���g�ɓn���Ă�����K�v�����肻���B
/// �E�v���C���[�͌��ݑ����Ă��܂��B=> GraphicsComponent�͑����Ă����`�悷��B
/// 
/// �R���|�[�l���g
/// �ETransform
/// �EPhysics
/// �ERendering
/// �EInput
