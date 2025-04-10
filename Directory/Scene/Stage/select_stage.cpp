#include "ipc.hpp"
#include "select_stage.hpp"

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

SelectScene::SelectScene(SceneManager& manager)
    : SceneBase{ manager, SceneTag.SELECT }
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::Initialise()
{
    m_timeFromScene = 0.0f;
}

void SelectScene::Update(const float& deltaTime)
{
	SceneFinaliseCondition();
}

void SelectScene::Render() const
{
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%s : %.2f",
		const_cast<char*>(m_tag.c_str()), m_timeFromScene);
}

void SelectScene::UpdateTimer(const float& deltaTime)
{
	m_timeFromScene += deltaTime;
}

/*===============================================================*\
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/

// TODO: �R���g���[���[�ŃL�[�ݒ肷��
void SelectScene::SceneFinaliseCondition()
{
	// �^�C�g���ɖ߂�
	if (CheckHitKey(KEY_INPUT_T))
	{
		ChangeScene("Title");
		return;
	}

	if (CheckHitKey(KEY_INPUT_1))
	{
		ChangeScene("Stage");
	}

	return;
}
