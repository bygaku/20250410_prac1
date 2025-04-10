#pragma once
#include "Component/component_base.hpp"

class CameraComponent : public Component
{
public:
	CameraComponent(std::weak_ptr<Object> object);

	virtual ~CameraComponent() override = default;

	/// @brief �J�����O�X�V����.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief �J�����X�V����.
	virtual void Update(const float& deltaTime) override;

	/// @brief �J������X�V����.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief �J�����`�揈��.
	virtual void Render() override {};

	/// @brief �J�����������.
	virtual void Exit() override {};

	/// @brief �I�t�Z�b�g�l��ݒ�.
	void SetOffset(const VECTOR& offset);
private:
	const float k_near;				/// @brief �ŏ��`�拗��
	const float k_far;				/// @brief �ő�`�拗��
	VECTOR m_lookPos;
	VECTOR m_movePos;
	VECTOR m_offset;				/// @brief �J�����̃I�t�Z�b�g�l
};


