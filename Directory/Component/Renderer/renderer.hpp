#pragma once
#include "Component/component_base.hpp"

class RendererComponent : public Component
{
public:
	/// @brief �R���X�g���N�^.
	RendererComponent(std::weak_ptr<Object> object);

	/// @brief �f�t�H���g�f�X�g���N�^.
	virtual ~RendererComponent() override = default;

	/// @brief Renderer�O�X�V����.
	virtual void PreUpdate(const float& deltaTime) override {};

	/// @brief Renderer�X�V����.
	virtual void Update(const float& deltaTime) override;

	/// @brief Renderer��X�V����.
	virtual void PostUpdate(const float& deltaTime) override {};

	/// @brief Renderer�`�揈��.
	virtual void Render() override;

	/// @brief Renderer�������.
	virtual void Exit() override {};
};
