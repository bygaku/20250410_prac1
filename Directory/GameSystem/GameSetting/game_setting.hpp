#pragma once
#include "memory"

/// ゲーム設定, ライブラリ初期化
class GameSetting final
{
public:
    /// @brief ゲーム設定, ライブラリの初期化
    static void Initialise();

    /// @brief デストラクタ
    ~GameSetting();

private:
    /// @brief コンストラクタ
    GameSetting();

    /// @brief ライブラリ初期化前
    static void BeforeLibInit();

    /// @brief ライブラリ初期化後
    static void AfterLibInit();

    /// @brief 禁止事項
    GameSetting(const GameSetting&) = delete;
    GameSetting& operator=(const GameSetting&) = delete;

private:
    static std::unique_ptr<GameSetting> m_instance;   /// @brief このクラスの実体

};

