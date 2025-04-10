#include "ipc.hpp"
#include "GameSystem/GameManager/game_manager.hpp"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // �Q�[���Ǘ�
    GameManager::Create();
    GameManager::GetInstance().Initialise();
    GameManager::GetInstance().PlayGame();
    GameManager::GetInstance().End();
    GameManager::Destroy();

    // �\�t�g�I��
    return 0;
}