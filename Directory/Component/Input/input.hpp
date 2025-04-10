#pragma once
#include "Component/component_base.hpp"

class InputComponent : public Component
{
public:
	/// @brief �R���X�g���N�^
	InputComponent(std::weak_ptr<Object> object);

	/// @brief �f�t�H���g�f�X�g���N�^
	virtual ~InputComponent() override = default;

	/// @brief InputPlayer�O�X�V����
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief InputPlayer�X�V����
	virtual void Update(const float& deltaTime) override;

	/// @brief InputPlayer��X�V����
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief InputPlayer�`�揈��
	virtual void Render() override {};

	/// @brief InputPlayer�������
	virtual void Exit() override {};

	#pragma region �O���Ɍ��J������͏��

	/// @brief ���X�e�B�b�N�X��X�̗�
	float GetLeftHorizontal() const { return m_LX; };
	/// @brief ���X�e�B�b�N�X��Y�̗�
	float GetLeftVertical() const { return m_LY; };


	/// @brief �E�X�e�B�b�N�X��X�̗�
	float GetRightHorizontal() const { return m_RX; };
	/// @brief �E�X�e�B�b�N�X��Y�̗�
	float GetRightVertical() const { return m_RY; };

#pragma endregion
private:
	/// �f�b�h�]�[������
	float ApplyDeadZone(float value) const;

private:
	float m_LX;
	float m_LY;
	float m_RX;
	float m_RY;

	const float k_deadZone	= 0.3f;

};
