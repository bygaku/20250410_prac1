#include "DxLib.h"
#include "game_setting.hpp"

std::unique_ptr<GameSetting> GameSetting::m_instance = nullptr;

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

void GameSetting::Initialise()
{
    if (m_instance) return;
    m_instance.reset(new GameSetting());
}

GameSetting::~GameSetting()
{
    // ライブラリ終了
    DxLib_End();
}

/*===============================================================*\
 * ・プライベートメソッド
\*===============================================================*/

GameSetting::GameSetting()
{
    BeforeLibInit();

    // 初期化失敗
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

    // Zバッファ設定
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
    SetUseBackCulling(true);

    // 標準ライトを無効化
    //SetLightEnable(false);
    //SetUsePixelLighting(true);
}