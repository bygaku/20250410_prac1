/*==========================================================*\
 * @brief  [int] window size (16:9).
\*==========================================================*/
#pragma once
#include "utility"

/// @brief ウィンドウデータ.
class WindowData final
{
public:
#ifdef _RELEASE
    static constexpr int kWidth  = 1920;    /// @brief 横 _RELEASE mode
    static constexpr int kHeight = 1080;    /// @brief 縦 _RELEASE mode
#else
    static constexpr int kWidth  = 1280;    /// @brief 横 _DEBUG mode
    static constexpr int kHeight =  720;    /// @brief 縦 _DEBUG mode
#endif // Release mode

    static constexpr int kColorBit = 16;    /// @brief カラービット

public:
    /// @brief コンストラクタ.
    WindowData()
    { 
        // no processing
    };

};

