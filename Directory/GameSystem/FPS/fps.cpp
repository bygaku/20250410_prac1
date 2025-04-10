#include "DxLib.h"
#include "iostream"
#include "fps.hpp"

FPS* FPS::m_instance = nullptr;

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

void FPS::Create()
{
    // �C���X�^���X���쐬����Ă���
    if (m_instance)
    {
        std::cerr << "[FPS] Error: Instance already exist.\n";
        std::terminate();
    }

    m_instance = new FPS();
}

void FPS::Destroy()
{
    // �C���X�^���X���쐬����Ă��Ȃ�
    if (!m_instance)
    {
        std::cerr << "[FPS] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    delete m_instance;
}

FPS& FPS::GetInstance()
{
    // �C���X�^���X���쐬����Ă��Ȃ�
    if (!m_instance) 
    {
        std::cerr << "[FPS] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    return *m_instance;
}

void FPS::Initialise()
{
    // �N���̃^�C�~���O�ŃV�X�e�����Ԃ���
    m_time                  = GetNowHiPerformanceCount();
    m_fpsCheckTime          = GetNowHiPerformanceCount();
    m_fixedUpdateCheckTime  = GetNowHiPerformanceCount();
}

void FPS::IncrementFrame()
{
    // �f���^�^�C�����Z�o
    const LONGLONG now = GetNowHiPerformanceCount();
    m_dt     = (now - m_time) / 1000000.0f;
    m_time   =  now;

    // 1�b�o�߂���ԂɎ��s���ꂽ���C�����[�v�̉񐔂� FPS �Ƃ���
    ++m_fpsCounter;
    if (now - m_fpsCheckTime > 1000000.0f)
    {
        m_fps = m_fpsCounter;
        m_fpsCounter = 0;
        m_fpsCheckTime = now;
    }

    // deltatime�𖈃t���[�������āA�b���Z�o
    m_timeSinceStartUp += m_dt;
}

int FPS::UpdateFixedFrameCount()
{
    int frame_counts = 0;
    while (m_fixedUpdateCheckTime < m_time)
    {
        m_fixedUpdateCheckTime += 20000;
        frame_counts++;
    }

    m_lastFixedFrameCount = frame_counts;
    return frame_counts;
}

double FPS::GetCurrentFrameTime() const
{
    // 1�t���[���̎��Ԃ��Z�o
    const LONGLONG now = GetNowHiPerformanceCount();
    return (now - m_time) / 1000000.0;
}

void FPS::SleepForNextFrame() const
{
    auto frametime = GetCurrentFrameTime();
    if (GetSecondsPerFrame() > frametime) 
    {
        WaitTimer(static_cast<int>(GetSecondsPerFrame() - frametime) * 1000);
    }
}

void FPS::SetFpsTarget(int target)
{
    if (target == -1)
    {
        m_fpsTarget = target;
        m_secondsPerFrame = 0;
        return;
    }

    m_fpsTarget = target;
    m_secondsPerFrame = 1.0 / m_fpsTarget;
}

/*===============================================================*\
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/
