#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "input.hpp"

InputComponent::InputComponent(std::weak_ptr<Object> object)
    : Component { object }
    , m_LX(0.0f)
    , m_LY(0.0f)
    , m_RX(0.0f)
    , m_RY(0.0f)
{
}

void InputComponent::Update(const float& deltaTime)
{
    XINPUT_STATE input;
    
    if (GetJoypadXInputState(DX_INPUT_PAD1, &input) == 0)
    {
        // 左スティックのX軸（移動）
        const float norm = 32767.0f;
        
        float lStickX = input.ThumbLX / norm;
        float lStickY = input.ThumbLY / norm;
        float rStickX = input.ThumbRX / norm;
        float rStickY = input.ThumbRY / norm;

        m_LX = ApplyDeadZone(lStickX);
        m_LY = ApplyDeadZone(lStickY);
        m_RX = ApplyDeadZone(rStickX);
        m_RY = ApplyDeadZone(rStickY);
    }
    else
    {
        m_LX = 0.0f;
        m_LY = 0.0f;
        m_RX = 0.0f;
        m_RY = 0.0f;
    }

    //if (CheckHitKey(KEY_INPUT_RIGHT))
    //{
    //    m_horizontal += 5;
    //}
    //else
    //{
    //    m_horizontal = 0;
    //}

    //if (CheckHitKey(KEY_INPUT_LEFT))
    //{
    //    m_horizontal--;
    //}
    //else
    //{
    //    m_horizontal = 0;
    //}
}

float InputComponent::ApplyDeadZone(float value) const
{
    if (fabsf(value) < k_deadZone) { return 0.0f; }
    return value;
}
