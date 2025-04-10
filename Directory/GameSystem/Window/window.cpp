#include "DxLib.h"
#include "window_data.hpp"
#include "window.hpp"

std::unique_ptr<Window> Window::m_instance = nullptr;

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

void Window::Initialise()
{
    if (m_instance) return;
    m_instance.reset(new Window());
}

/*===============================================================*\
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/

Window::Window()
{
    // �o�̓E�B���h�E�̏������ݒ�
    ChangeWindowMode(true);
    SetGraphMode(WindowData::kWidth, WindowData::kHeight, WindowData::kColorBit);
    SetDrawScreen(DX_SCREEN_BACK);

    SetMainWindowText("Rooftop Runner");
}
