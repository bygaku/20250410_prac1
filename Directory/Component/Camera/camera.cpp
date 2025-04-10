#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "camera.hpp"
#include "Component/Input/input.hpp"

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

CameraComponent::CameraComponent(std::weak_ptr<Object> object)
    : Component { object }
    , k_near(1.0f/*float(Json::getInstance()->GetData()["CameraNear"])*/)
    , k_far (1000.0f/*float(Json::getInstance()->GetData()["CameraFar"])*/)
    , m_offset (VGet(0.0f, 0.0f, 0.0f))
    , m_lookPos(VGet(0.0f, 100.0f, 0.0f))
    , m_movePos(VGet(0.0f, 200.f, 0.0f))
{
    SetCameraNearFar(k_near, k_far);
}

void CameraComponent::Update(const float& deltaTime)
{	
    auto input = GetOwner().lock()->GetComponent<InputComponent>();
    

    if (input)
    {
        m_lookPos.x += input->GetHorizontal();
        m_movePos.x += input->GetHorizontal();     

        m_lookPos.y += input->GetVertical();
        m_movePos.y += input->GetVertical();

        DrawString(0, 80, "Xinput: LStick�ŃJ�������W�̈ړ�", GetColor(255, 0, 0));
    }

    // �J�����̈ʒu��ݒ� *�����l
    SetCameraPositionAndTarget_UpVecY(VGet(m_movePos.x, m_movePos.y, -500.0f), m_lookPos);
}

/// @brief �J�����̏����l
void CameraComponent::SetOffset(const VECTOR& offset)
{
    m_offset = offset;
}
