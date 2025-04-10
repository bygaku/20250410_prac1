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

	/// @brief �X��X�̗�
	float GetHorizontal() const { return m_horizontal; };
	/// @brief �X��Y�̗�
	float GetVertical() const { return m_vertical; };
#pragma endregion
private:
	/// �f�b�h�]�[������
	float ApplyDeadZone(float value) const;

private:
	float m_horizontal;
	float m_vertical;

	const float k_deadZone	= 0.2f;

};
