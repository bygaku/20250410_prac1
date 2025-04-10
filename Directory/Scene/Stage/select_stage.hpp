#pragma once
#include "../SceneBase/scene_base.hpp"

/// @brief �X�e�[�W�Z���N�g�V�[���N���X.
/// @remark SceneManager�N���X�ŌĂ΂�܂�
class SelectScene : public SceneBase
{
public:
	/// @brief �R���X�g���N�^.
	/// @param manager SceneManager �̎Q��
	SelectScene(SceneManager& manager);

	/// @brief �f�X�g���N�^.
	virtual ~SelectScene() override;

	/// @brief �Z���N�g�V�[��������.
	/// @remark �����[�h�̎��Ɉꏏ�ɏ������������f�[�^������
	virtual void Initialise() override;

	/// @brief �Z���N�g�V�[���X�V.
	virtual void Update(const float& deltaTime) override;

	/// @brief �Z���N�g�V�[���`��.
	virtual void Render() const override;

	/// @brief �J�E���g�A�b�v�^�C�}�[���Z�b�g.
	virtual void UpdateTimer(const float& deltaTime) override;

private:
	/// @brief �V�[����[��n��]�̏�����.
	virtual void SceneFinaliseCondition() override;


};
