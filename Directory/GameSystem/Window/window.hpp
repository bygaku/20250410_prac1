#pragma once
#include "memory"
#include "utility"

/// @brief ウィンドウ.
class Window final
{
public:
    /// @brief ウィンドウの初期化
    static void Initialise();

    /// @brief デストラクタ
    ~Window() = default;

private:
    /// @brief コンストラクタ
    Window();

    /// @brief 禁止事項
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    static std::unique_ptr<Window> m_instance;    /// @brief このクラスの実体

};

