#pragma once
#include "memory"
#include "utility"

/// @brief �E�B���h�E.
class Window final
{
public:
    /// @brief �E�B���h�E�̏�����
    static void Initialise();

    /// @brief �f�X�g���N�^
    ~Window() = default;

private:
    /// @brief �R���X�g���N�^
    Window();

    /// @brief �֎~����
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    static std::unique_ptr<Window> m_instance;    /// @brief ���̃N���X�̎���

};

