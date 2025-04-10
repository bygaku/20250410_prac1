#include "ipc.hpp"
#include "Object/ObjectBase/object_base.hpp"
#include "model.hpp"

/*===============================================================*\
 * ・パブリックメソッド
\*===============================================================*/

ModelComponent::ModelComponent(std::weak_ptr<Object> object)
    : Component { object }
    , m_modelHandle(-1)
    , m_visible    (true)
    , m_scale      (1.0f)
    , m_rota       (VGet(0.0f, 0.0f, 0.0f))
{
}

ModelComponent::~ModelComponent()
{
    if (m_modelHandle != -1) MV1DeleteModel(m_modelHandle);
}

void ModelComponent::Update(const float& deltaTime)
{
}

void ModelComponent::Render()
{
}

bool ModelComponent::LoadModel(const std::string& filePath)
{
    m_modelHandle = MV1LoadModel(filePath.c_str());
    return m_modelHandle != -1;
}
