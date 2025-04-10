/*==========================================================*\
 * @brief  [int] window size (16:9).
\*==========================================================*/
#pragma once
#include "utility"

/// @brief �E�B���h�E�f�[�^.
class WindowData final
{
public:
#ifdef _RELEASE
    static constexpr int kWidth  = 1920;    /// @brief �� _RELEASE mode
    static constexpr int kHeight = 1080;    /// @brief �c _RELEASE mode
#else
    static constexpr int kWidth  = 1280;    /// @brief �� _DEBUG mode
    static constexpr int kHeight =  720;    /// @brief �c _DEBUG mode
#endif // Release mode

    static constexpr int kColorBit = 16;    /// @brief �J���[�r�b�g

public:
    /// @brief �R���X�g���N�^.
    WindowData()
    { 
        // no processing
    };

};

