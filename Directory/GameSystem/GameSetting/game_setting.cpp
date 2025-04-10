#include "DxLib.h"
#include "game_setting.hpp"

std::unique_ptr<GameSetting> GameSetting::m_instance = nullptr;

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

void GameSetting::Initialise()
{
    if (m_instance) return;
    m_instance.reset(new GameSetting());
}

GameSetting::~GameSetting()
{
    // ���C�u�����I��
    DxLib_End();
}

/*===============================================================*\
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/

GameSetting::GameSetting()
{
    BeforeLibInit();

    // ���������s
    if (DxLib_Init() == -1)
    {
        DebugBreak();
    }

    AfterLibInit();
}

void GameSetting::BeforeLibInit()
{
    SetUseDirect3DVersion(DX_DIRECT3D_11);
}

void GameSetting::AfterLibInit()
{
    SetDrawScreen(DX_SCREEN_BACK);

    // Z�o�b�t�@�ݒ�
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
    SetUseBackCulling(true);

    // �W�����C�g�𖳌���
    //SetLightEnable(false);
    //SetUsePixelLighting(true);
}