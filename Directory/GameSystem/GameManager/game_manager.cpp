#include "ipc.hpp"

#include "GameSystem/Window/window.hpp"
#include "GameSystem/GameSetting/game_setting.hpp"
#include "GameSystem/FPS/fps.hpp"

#include "Object/ObjectManager/object_manager.hpp"

#include "game_manager.hpp"
#include "Component/Transform/transform.hpp"
#include "Component/Renderer/renderer.hpp"
#include "Component/Model/model.hpp"
#include "Component/Camera/camera.hpp"
#include "Component/Input/input.hpp"

GameManager* GameManager::m_instance = nullptr;

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

void GameManager::Create()
{
    // インスタンスが作成されている
    if (m_instance)
    {
        std::cerr << "[GameManager] Error: Instance already exist.\n";
        std::terminate();
    }

    m_instance = new GameManager();
}

void GameManager::Destroy()
{
    // インスタンスが作成されていない
    if (!m_instance) 
    {
        std::cerr << "[GameManager] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    delete m_instance;
}

GameManager& GameManager::GetInstance()
{
    // インスタンスが作成されていない
    if (!m_instance)
    {
        std::cerr << "[GameManager] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    return *m_instance;
}

void GameManager::Initialise()
{   
    FPS::GetInstance().Initialise();
    FPS::GetInstance().SetFpsTarget(60);

    // 今回はGameManagerで起動
    auto camera = m_objectManager->GenerateObject<Object>("Camera", "maincamera");

    auto cameraInput     = camera->AddComponent<InputComponent>();
    auto cameracomponent = camera->AddComponent<CameraComponent>();
    cameracomponent->SetOffset(VGet(0.0f, 200.0f, -500.0f));

    m_objectManager->AddObject(camera);
}

void GameManager::PlayGame()
{
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        ClearDrawScreen();

        m_objectManager->Update(FPS::GetInstance().GetDeltaTime());
        m_objectManager->Render();

#ifdef _DEBUG
        DrawFormatString(0, 0, GetColor(255, 0, 0), "%d",    FPS::GetInstance().GetFps());
        DrawFormatString(0, 20, GetColor(255, 0, 0), "%d",   FPS::GetInstance().GetFpsCounter());
        DrawFormatString(0, 40, GetColor(255, 0, 0), "%d",   FPS::GetInstance().GetFpsTarget());
        DrawFormatString(0, 60, GetColor(255, 0, 0), "%.2f", FPS::GetInstance().GetTimeFromBoot());

        float lineSize = 500.0f;
        DrawLine3D(VGet(-lineSize, 0, 0), VGet(lineSize, 0, 0), GetColor(255, 0, 0));
        DrawLine3D(VGet(0, -lineSize, 0), VGet(0, lineSize, 0), GetColor(0, 255, 0));
        DrawLine3D(VGet(0, 0, -lineSize), VGet(0, 0, lineSize), GetColor(0, 0, 255));

#endif // FPS/TIMEの表示

        FPS::GetInstance().SleepForNextFrame();
        ScreenFlip();
        FPS::GetInstance().IncrementFrame();
    }
}

void GameManager::End()
{
}

const float& GameManager::GetDeltaTime() const
{
    return FPS::GetInstance().GetDeltaTime();
}

/*===============================================================*\
 * ・プライベートメソッド
\*===============================================================*/

GameManager::GameManager()
{    
    // ログの非表示
    SetOutApplicationLogValidFlag(false);

    // 各初期化
    Window::Initialise();
    GameSetting::Initialise();

    // 明示的インスタンス作成
    FPS::Create();

    // 各マネージャー確保
    m_objectManager = std::make_shared<ObjectManager>();
}

GameManager::~GameManager()
{
    // 明示的インスタンス破棄
    FPS::Destroy();
}
