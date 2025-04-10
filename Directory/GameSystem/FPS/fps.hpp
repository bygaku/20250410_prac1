#pragma once
#include "memory"

/// @brief FPS管理
/// @remark
/// int main()
/// {
///   Initialise(); // GameTime の初期化
///   setFpsTarget(60); // fps を 60 に制限
///   
///   while (true)
///   {
///     /* 
///      * 更新処理に GetDeltaTime() をかけて速度一定化
///      */
///
///     SleepForNextFrame(); // fps 制限を掛けているときに、制限の時間まで待つ
///     ScreenFlip();
///     IncrementFrame();    // フレームカウントを更新し、deltatime を算出する
///   }
/// }
class FPS
{
public:	
    /// @brief 明示的インスタンス作成
    /// @return 早期return: すでにインスタンスを所持している
    static void Create();

    /// @brief 明示的インスタンス破棄
    /// @return 早期return: インスタンスを所持していない
    static void Destroy();

    /// @brief インスタンスを取得
    static FPS& GetInstance();

    /// @brief FPS の初期化
    void Initialise();

    /// @brief m_fpsTarget として指定されている時間まで待つ
    void SleepForNextFrame() const;

    /// @brief フレームカウントを +1 する
    /// @remark 毎フレーム処理前に呼び出す
    void IncrementFrame();

    /// @brief 固定フレームの更新回数を更新して返す
    int UpdateFixedFrameCount();

    /// @brief 現在のフレームの時間
    [[nodiscard]] const LONGLONG& GetTime() const { return m_time; }

    /// @brief 最後に fps を更新した時間 (nanoseconds)
    [[nodiscard]] const LONGLONG& GetLastCheckedTime() const { return m_fpsCheckTime; }

    /// @brief 2つ前と1つ前のフレーム間の時間差 (seconds)
    [[nodiscard]] const float& GetDeltaTime() const { return m_dt; }

    /// @brief 起動からの時間 (seconds)
    [[nodiscard]] const float& GetTimeFromBoot() const { return m_timeSinceStartUp; }

    /// @brief 現在の frames per second
    [[nodiscard]] const int& GetFps() const { return m_fps; };

    /// @brief 最後の fps 更新からのフレームカウント
    [[nodiscard]] const int& GetFpsCounter() const { return m_fpsCounter; };

    /// @brief 現在の fps 制限
    [[nodiscard]] const int& GetFpsTarget() const { return m_fpsTarget; };

    /// @brief 現在の fps 制限によるフレーム間の秒数 (seconds)
    [[nodiscard]] const double& GetSecondsPerFrame() const { return m_secondsPerFrame; };

    /// @brief 最後の固定間隔更新の回数
    [[nodiscard]] const int& GetLastFixedFrameCount() const { return m_lastFixedFrameCount; };

    /// @brief 起動してからのフレーム数
    [[nodiscard]] const unsigned int& GetFrames() const { return m_frames; };

    /// @brief 現在の1フレーム処理時間 (seconds)
    [[nodiscard]] double GetCurrentFrameTime() const;

    /// @brief fps 制限を指定する
    void SetFpsTarget(int target);
private:
    /// @brief コンストラクタ
    /// @brief 初期化のみ
    FPS()
        : m_time(0)
        , m_fpsCheckTime(0)
        , m_fixedUpdateCheckTime(0)
        , m_dt(0.0f)
        , m_timeSinceStartUp(0.0f)
        , m_fps(0)
        , m_fpsCounter(0)
        , m_lastFixedFrameCount(0)
        , m_fpsTarget(0)
        , m_secondsPerFrame(1.0 / m_fpsTarget)
        , m_frames(0)
    {
    };

    /// @brief デフォルトデストラクタ
    ~FPS() = default;

    /// @brief 禁止事項
    FPS(const FPS&) = delete;
    FPS& operator=(const FPS&) = delete;

private:
    static FPS* m_instance;

    LONGLONG m_time;
    LONGLONG m_fpsCheckTime;
    LONGLONG m_fixedUpdateCheckTime;
    float    m_dt;
    float    m_timeSinceStartUp;
    int      m_fps;
    int      m_fpsCounter;
    int      m_lastFixedFrameCount;
    int      m_fpsTarget;

    double   m_secondsPerFrame;

    unsigned int m_frames;

};
