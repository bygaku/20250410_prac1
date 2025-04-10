#include "ipc.hpp"
#include "GameSystem/GameManager/game_manager.hpp"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // ゲーム管理
    GameManager::Create();
    GameManager::GetInstance().Initialise();
    GameManager::GetInstance().PlayGame();
    GameManager::GetInstance().End();
    GameManager::Destroy();

    // ソフト終了
    return 0;
}