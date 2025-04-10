#include "DxLib.h"
#include "window_data.hpp"
#include "window.hpp"

std::unique_ptr<Window> Window::m_instance = nullptr;

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

void Window::Initialise()
{
    if (m_instance) return;
    m_instance.reset(new Window());
}

/*===============================================================*\
 * ・プライベートメソッド
\*===============================================================*/

Window::Window()
{
    // 出力ウィンドウの初期化設定
    ChangeWindowMode(true);
    SetGraphMode(WindowData::kWidth, WindowData::kHeight, WindowData::kColorBit);
    SetDrawScreen(DX_SCREEN_BACK);

    SetMainWindowText("Rooftop Runner");
}
