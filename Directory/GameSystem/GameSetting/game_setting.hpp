#pragma once
#include "memory"

/// �Q�[���ݒ�, ���C�u����������
class GameSetting final
{
public:
    /// @brief �Q�[���ݒ�, ���C�u�����̏�����
    static void Initialise();

    /// @brief �f�X�g���N�^
    ~GameSetting();

private:
    /// @brief �R���X�g���N�^
    GameSetting();

    /// @brief ���C�u�����������O
    static void BeforeLibInit();

    /// @brief ���C�u������������
    static void AfterLibInit();

    /// @brief �֎~����
    GameSetting(const GameSetting&) = delete;
    GameSetting& operator=(const GameSetting&) = delete;

private:
    static std::unique_ptr<GameSetting> m_instance;   /// @brief ���̃N���X�̎���

};

