#include "animator.hpp"

Animator::Animator(Animation* current) {
	this->m_CurrentAnimation = current;
	this->m_CurrentTime = 0.0;
	this->m_Transforms.reserve(100);
	for (int i = 0; i < 100; i++) {
		this->m_Transforms.push_back(glm::mat4(1.0f));
	}
}

std::vector<glm::mat4> Animator::GetPoseTransforms() const {
	return this->m_Transforms;
}

void Animator::UpdateAnimation(float dt) {
	this->m_DeltaTime = dt;
	if (this->m_CurrentAnimation) {
		this->m_CurrentTime += this->m_CurrentAnimation->GetTicksPerSecond() * dt;
		this->m_CurrentTime = fmod(this->m_CurrentTime, this->m_CurrentAnimation->GetDuration());
		this->CalculateBoneTransform(&this->m_CurrentAnimation->GetRootNode(), glm::mat4(1.0f));
	}
}

void Animator::PlayAnimation(Animation* pAnimation) {
	this->m_CurrentAnimation = pAnimation;
	this->m_CurrentTime = 0.0f;
}

void Animator::CalculateBoneTransform(const AssimpNodeData* node, glm::mat4 parentTransform) {
	std::string nodeName = node->name;
	glm::mat4 nodeTransform = node->transformation;

	Bone* Bone = this->m_CurrentAnimation->FindBone(nodeName);

	if (Bone) {
		Bone->Update(m_CurrentTime);
		nodeTransform = Bone->GetLocalTransform();
	}

	glm::mat4 globalTransformation = parentTransform * nodeTransform;

	auto boneInfoMap = this->m_CurrentAnimation->GetBoneIDMap();
	if (boneInfoMap.find(nodeName) != boneInfoMap.end()) {
		int index = boneInfoMap[nodeName].id;
		glm::mat4 offset = boneInfoMap[nodeName].offset;
		this->m_Transforms[index] = globalTransformation * offset;
	}

	for (int i = 0; i < node->childrenCount; i++) {
		this->CalculateBoneTransform(&node->children[i], globalTransformation);
	}
}