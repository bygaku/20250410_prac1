#pragma once
#include "Component/component_base.hpp"

class TransformComponent : public Component
{
public:
	/// @brief �R���X�g���N�^.
	TransformComponent(std::weak_ptr<Object> object/*, const float& scale*/);

	/// @brief �f�t�H���g�f�X�g���N�^.
	virtual ~TransformComponent() override = default;

	/// @brief Transform�O�X�V����.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Transform�X�V����.
	virtual void Update(const float& deltaTime) override;

	/// @brief Transform��X�V����.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Transform�`�揈��.
	virtual void Render() override {};

	/// @brief Transform�������.
	virtual void Exit() override {};

	/// @brief ���[���h���W�̎擾.
	//const VECTOR& GetWorldPosition() const { return m_objWorldPos; };

	/// @brief ���W�̎擾.
	const VECTOR& GetPosition() const { return m_objPos; };

	/// @brief ��]�̎擾.
	const VECTOR& GetRotation() const { return m_objRota; };

	/// @brief �T�C�Y�̎擾.
	const VECTOR& GetScale() const { return m_objScale; };

	VECTOR	m_objPos;			/// @brief ���W
protected:
	/// @brief �I�u�W�F�N�g�̍��W���Z�o.
	void CalcObjPos() { m_objPos = VAdd(m_objWorldPos, m_objLocalPos); };

private:
	VECTOR	m_objWorldPos;		/// @brief ���[���h���W
	VECTOR	m_objLocalPos;		/// @brief ���[�J�����W
	VECTOR	m_objRota;			/// @brief ��]
	VECTOR	m_objScale;			/// @brief �I�u�W�F�N�g�̑傫��
};
