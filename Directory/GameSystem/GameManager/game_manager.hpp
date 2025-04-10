#pragma once

class ObjectManager;
class SceneManager;
class FPS;
class SceneBase;

/// @brief �Q�[���v���Z�X�Ǘ�
class GameManager final : public std::enable_shared_from_this<GameManager>
{
public:
    /// @brief �����I�C���X�^���X�쐬
    /// @return ����return: ���łɃC���X�^���X���������Ă���
    static void Create();

    /// @brief �����I�C���X�^���X�j��
    /// @return ����return: �C���X�^���X���������Ă��Ȃ�
    static void Destroy();

    /// @brief �C���X�^���X���擾
    static GameManager& GetInstance();

    /// @brief �Q�[���̏�����
    void Initialise();

    /// @brief �Q�[���v���C��/�X�V
    void PlayGame();

    /// @brief �Q�[���̏I��/�j��
    void End();

    #pragma region �Q�[���Ǘ��o�^�I�u�W�F�N�g�̃A�N�Z�T.
    /// @brief �I�u�W�F�N�g�Ǘ��̎擾
    ObjectManager& GetObjectManager() const { return *m_objectManager; };

    /// @brief �f���^�^�C���̎擾
    const float& GetDeltaTime() const;
    #pragma endregion
private:
    /// @remark ���C�u����������
    GameManager();

    /// @remark �f�X�g���N�^
    ~GameManager();

    /// @brief �֎~����
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

#ifdef _DEBUG
    void RenderFloorGrid() const;
#endif // DEBUG

private:
    static GameManager* m_instance;                 /// @brief ���̃N���X�̎���

    std::shared_ptr<ObjectManager> m_objectManager; /// @brief �I�u�W�F�N�g�Ǘ�
    //std::shared_ptr<SoundManager>  m_soundManager;  ///@brief �T�E���h�Ǘ�
};