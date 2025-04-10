#pragma once
#include "Component/component_base.hpp"

class ModelComponent : public Component
{
public:
	/// @brief �R���X�g���N�^.
	ModelComponent(std::weak_ptr<Object> object);

	/// @brief �f�X�g���N�^.
	virtual ~ModelComponent() override;

	/// @brief Model�O�X�V����.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Model�X�V����.
	virtual void Update(const float& deltaTime) override;

	/// @brief Model��X�V����.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Model�`�揈��.
	virtual void Render() override;

	/// @brief Model�������.
	virtual void Exit() override {};

	/// @brief ���f���̓ǂݍ���.
	/// @param filePath �t�@�C����
	bool LoadModel(const std::string& filePath);

	/// @brief ����ݒ�.
	void SetVisible(bool visible) { m_visible = visible; };

	/// @brief �T�C�Y��ݒ�.
	/// @param scale float 1.0f = �ʏ�̃T�C�Y
	void SetScale(float scale) { m_scale = scale; };

	/// @brief ��]��ݒ�.
	/// @param rotation VECTOR { x, y , z }
	void SetRotation(const VECTOR& rotation) { m_rota = rotation; };

	/// @brief 3D���f���n���h���̎擾.
	int GetModelHandle() const { return m_modelHandle; }

private:
	int		m_modelHandle;
	bool	m_visible;
	float	m_scale;
	VECTOR	m_rota;

};
