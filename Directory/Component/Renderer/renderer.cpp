#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "renderer.hpp"
#include "../Transform/transform.hpp"
#include "../Model/model.hpp"

/*===============================================================*\
 * �E�p�u���b�N���\�b�h
\*===============================================================*/

RendererComponent::RendererComponent(std::weak_ptr<Object> object)
    : Component { object }
{
}

void RendererComponent::Update(const float& deltaTime)
{
    auto transform = GetOwner().lock()->GetComponent<TransformComponent>();
    auto model     = GetOwner().lock()->GetComponent<ModelComponent> ();

    if (!transform || !model) return;

    int modelHandle = model->GetModelHandle();
    if (modelHandle == -1) return;

    // �A�j���[�V����������Ȃ�K�p
    //auto animator = GetOwner().lock()->GetComponent<AnimatorComponent>();
    //if (animator) {
    //    MV1AttachAnim(modelHandle, animator->GetCurrentAnimIndex(), -1, FALSE);
    //    MV1SetAttachAnimTime(modelHandle, animator->GetCurrentAnimIndex(), animator->GetCurrentAnimTime());
    //}

    // ���f���̈ʒu�E��]�E�X�P�[����ݒ�
    MV1SetScale      (modelHandle, transform->GetScale());
    MV1SetRotationXYZ(modelHandle, transform->GetRotation());
    MV1SetPosition   (modelHandle, transform->GetPosition());
}

void RendererComponent::Render()
{
    auto model = GetOwner().lock()->GetComponent<ModelComponent>();
    int modelHandle = model->GetModelHandle();

    // �`��
    MV1DrawModel(modelHandle);
}

