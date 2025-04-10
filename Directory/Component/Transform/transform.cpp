#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "transform.hpp"

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

TransformComponent::TransformComponent(std::weak_ptr<Object> object/*, const float& scale*/)
    : Component{ object }
    , m_objWorldPos(VGet(0.0f, 0.0f, 0.0f))
    , m_objLocalPos(VGet(0.0f, 0.0f, 0.0f))
    , m_objPos(VGet(0.0f, 0.0f, 0.0f))
    , m_objRota(VGet(0.0f, 0.0f, 0.0f))
    , m_objScale(VGet(1.0f, 1.0f, 1.0f))
{
}

void TransformComponent::Update(const float& deltaTime)
{
    //CalcObjPos();
}
