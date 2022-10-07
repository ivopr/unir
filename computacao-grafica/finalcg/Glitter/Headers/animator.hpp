#pragma once

#include <glm/glm.hpp>
#include <map>
#include <vector>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include "animation.hpp"
#include "bone.hpp"

class Animator {
public:
	Animator(Animation* current);

	void UpdateAnimation(float dt);

	void PlayAnimation(Animation* pAnimation);

	void CalculateBoneTransform(const AssimpNodeData* node, glm::mat4 parentTransform);

	std::vector<glm::mat4> GetPoseTransforms() const;

private:
	std::vector<glm::mat4> m_Transforms;
	Animation* m_CurrentAnimation;
	float m_CurrentTime;
	float m_DeltaTime;
};