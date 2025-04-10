#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "renderer.hpp"
#include "../Transform/transform.hpp"
#include "../Model/model.hpp"

/*===============================================================*\
 * ・パブリックメソッド
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

    // アニメーションがあるなら適用
    //auto animator = GetOwner().lock()->GetComponent<AnimatorComponent>();
    //if (animator) {
    //    MV1AttachAnim(modelHandle, animator->GetCurrentAnimIndex(), -1, FALSE);
    //    MV1SetAttachAnimTime(modelHandle, animator->GetCurrentAnimIndex(), animator->GetCurrentAnimTime());
    //}

    // モデルの位置・回転・スケールを設定
    MV1SetScale      (modelHandle, transform->GetScale());
    MV1SetRotationXYZ(modelHandle, transform->GetRotation());
    MV1SetPosition   (modelHandle, transform->GetPosition());
}

void RendererComponent::Render()
{
    auto model = GetOwner().lock()->GetComponent<ModelComponent>();
    int modelHandle = model->GetModelHandle();

    // 描画
    MV1DrawModel(modelHandle);
}

