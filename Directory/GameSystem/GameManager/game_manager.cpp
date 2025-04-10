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
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

void GameManager::Create()
{
    // �C���X�^���X���쐬����Ă���
    if (m_instance)
    {
        std::cerr << "[GameManager] Error: Instance already exist.\n";
        std::terminate();
    }

    m_instance = new GameManager();
}

void GameManager::Destroy()
{
    // �C���X�^���X���쐬����Ă��Ȃ�
    if (!m_instance) 
    {
        std::cerr << "[GameManager] Error: Instance not created. Call Create() first.\n";
        std::terminate();
    }

    delete m_instance;
}

GameManager& GameManager::GetInstance()
{
    // �C���X�^���X���쐬����Ă��Ȃ�
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

    // �����GameManager�ŋN��
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

        RenderFloorGrid();
#endif // FPS/TIME�̕\��

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
 * �E�v���C�x�[�g���\�b�h
\*===============================================================*/

GameManager::GameManager()
{    
    // ���O�̔�\��
    SetOutApplicationLogValidFlag(false);

    // �e������
    Window::Initialise();
    GameSetting::Initialise();

    // �����I�C���X�^���X�쐬
    FPS::Create();

    // �e�}�l�[�W���[�m��
    m_objectManager = std::make_shared<ObjectManager>();
}

GameManager::~GameManager()
{
    // �����I�C���X�^���X�j��
    FPS::Destroy();
}

#ifdef _DEBUG
void GameManager::RenderFloorGrid() const
{
    float lineSize = 4000.0f;
    for (int i = -16; i < 26; i++)
    {
        auto grid = static_cast<float>(i * 200);
        DrawLine3D(VGet(-lineSize, 0, grid), VGet(lineSize, 0, grid), GetColor(255, 0, 0));
        DrawLine3D(VGet(grid, 0, -lineSize), VGet(grid, 0, lineSize), GetColor(0, 0, 255));
    }

    DrawLine3D(VGet(0, -lineSize, 0), VGet(0, lineSize, 0), GetColor(0, 255, 0));

}
#endif // _DEBUG
