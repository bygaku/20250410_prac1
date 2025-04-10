#pragma once

class ObjectManager;
class SceneManager;
class FPS;
class SceneBase;

/// @brief ゲームプロセス管理
class GameManager final : public std::enable_shared_from_this<GameManager>
{
public:
    /// @brief 明示的インスタンス作成
    /// @return 早期return: すでにインスタンスを所持している
    static void Create();

    /// @brief 明示的インスタンス破棄
    /// @return 早期return: インスタンスを所持していない
    static void Destroy();

    /// @brief インスタンスを取得
    static GameManager& GetInstance();

    /// @brief ゲームの初期化
    void Initialise();

    /// @brief ゲームプレイ中/更新
    void PlayGame();

    /// @brief ゲームの終了/破棄
    void End();

    #pragma region ゲーム管理登録オブジェクトのアクセサ.
    /// @brief オブジェクト管理の取得
    ObjectManager& GetObjectManager() const { return *m_objectManager; };

    /// @brief デルタタイムの取得
    const float& GetDeltaTime() const;
    #pragma endregion
private:
    /// @remark ライブラリ初期化
    GameManager();

    /// @remark デストラクタ
    ~GameManager();

    /// @brief 禁止事項
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

private:
    static GameManager* m_instance;                 /// @brief このクラスの実体

    std::shared_ptr<ObjectManager> m_objectManager; /// @brief オブジェクト管理
    //std::shared_ptr<SoundManager>  m_soundManager;  ///@brief サウンド管理
};