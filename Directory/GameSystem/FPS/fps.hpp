#pragma once
#include "memory"

/// @brief FPS�Ǘ�
/// @remark
/// int main()
/// {
///   Initialise(); // GameTime �̏�����
///   setFpsTarget(60); // fps �� 60 �ɐ���
///   
///   while (true)
///   {
///     /* 
///      * �X�V������ GetDeltaTime() �������đ��x��艻
///      */
///
///     SleepForNextFrame(); // fps �������|���Ă���Ƃ��ɁA�����̎��Ԃ܂ő҂�
///     ScreenFlip();
///     IncrementFrame();    // �t���[���J�E���g���X�V���Adeltatime ���Z�o����
///   }
/// }
class FPS
{
public:	
    /// @brief �����I�C���X�^���X�쐬
    /// @return ����return: ���łɃC���X�^���X���������Ă���
    static void Create();

    /// @brief �����I�C���X�^���X�j��
    /// @return ����return: �C���X�^���X���������Ă��Ȃ�
    static void Destroy();

    /// @brief �C���X�^���X���擾
    static FPS& GetInstance();

    /// @brief FPS �̏�����
    void Initialise();

    /// @brief m_fpsTarget �Ƃ��Ďw�肳��Ă��鎞�Ԃ܂ő҂�
    void SleepForNextFrame() const;

    /// @brief �t���[���J�E���g�� +1 ����
    /// @remark ���t���[�������O�ɌĂяo��
    void IncrementFrame();

    /// @brief �Œ�t���[���̍X�V�񐔂��X�V���ĕԂ�
    int UpdateFixedFrameCount();

    /// @brief ���݂̃t���[���̎���
    [[nodiscard]] const LONGLONG& GetTime() const { return m_time; }

    /// @brief �Ō�� fps ���X�V�������� (nanoseconds)
    [[nodiscard]] const LONGLONG& GetLastCheckedTime() const { return m_fpsCheckTime; }

    /// @brief 2�O��1�O�̃t���[���Ԃ̎��ԍ� (seconds)
    [[nodiscard]] const float& GetDeltaTime() const { return m_dt; }

    /// @brief �N������̎��� (seconds)
    [[nodiscard]] const float& GetTimeFromBoot() const { return m_timeSinceStartUp; }

    /// @brief ���݂� frames per second
    [[nodiscard]] const int& GetFps() const { return m_fps; };

    /// @brief �Ō�� fps �X�V����̃t���[���J�E���g
    [[nodiscard]] const int& GetFpsCounter() const { return m_fpsCounter; };

    /// @brief ���݂� fps ����
    [[nodiscard]] const int& GetFpsTarget() const { return m_fpsTarget; };

    /// @brief ���݂� fps �����ɂ��t���[���Ԃ̕b�� (seconds)
    [[nodiscard]] const double& GetSecondsPerFrame() const { return m_secondsPerFrame; };

    /// @brief �Ō�̌Œ�Ԋu�X�V�̉�
    [[nodiscard]] const int& GetLastFixedFrameCount() const { return m_lastFixedFrameCount; };

    /// @brief �N�����Ă���̃t���[����
    [[nodiscard]] const unsigned int& GetFrames() const { return m_frames; };

    /// @brief ���݂�1�t���[���������� (seconds)
    [[nodiscard]] double GetCurrentFrameTime() const;

    /// @brief fps �������w�肷��
    void SetFpsTarget(int target);
private:
    /// @brief �R���X�g���N�^
    /// @brief �������̂�
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

    /// @brief �f�t�H���g�f�X�g���N�^
    ~FPS() = default;

    /// @brief �֎~����
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
