#include "DxLib.h"
#include "iostream"
#include "fps.hpp"

FPS* FPS::m_instance = nullptr;

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

void FPS::Create()
{
    // インスタンスが作成されている
    if (m_instance)
    {
        std::cerr << "[FPS] Error: Instance already exist.\n";
        std::terminate();
    }

    m_instance = new FPS();
}

void FPS::Destroy()
{
    // インスタンスが作成されていない
    if (!m_instance)
    {
        std::cerr << "[FPS] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    delete m_instance;
}

FPS& FPS::GetInstance()
{
    // インスタンスが作成されていない
    if (!m_instance) 
    {
        std::cerr << "[FPS] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    return *m_instance;
}

void FPS::Initialise()
{
    // 起動のタイミングでシステム時間を代入
    m_time                  = GetNowHiPerformanceCount();
    m_fpsCheckTime          = GetNowHiPerformanceCount();
    m_fixedUpdateCheckTime  = GetNowHiPerformanceCount();
}

void FPS::IncrementFrame()
{
    // デルタタイムを算出
    const LONGLONG now = GetNowHiPerformanceCount();
    m_dt     = (now - m_time) / 1000000.0f;
    m_time   =  now;

    // 1秒経過する間に実行されたメインループの回数を FPS とする
    ++m_fpsCounter;
    if (now - m_fpsCheckTime > 1000000.0f)
    {
        m_fps = m_fpsCounter;
        m_fpsCounter = 0;
        m_fpsCheckTime = now;
    }

    // deltatimeを毎フレーム足して、秒を算出
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
    // 1フレームの時間を算出
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
 * ・プライベートメソッド
\*===============================================================*/
