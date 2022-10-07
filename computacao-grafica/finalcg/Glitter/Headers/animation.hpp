#pragma once

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <assimp/scene.h>
#include "bone.hpp"
#include <functional>
#include "animdata.hpp"
#include "model_animation.hpp"

struct AssimpNodeData {
	glm::mat4 transformation;
	std::string name;
	int childrenCount;
	std::vector<AssimpNodeData> children;
};

class Animation {
public:
	Animation();
	~Animation();
	Animation(const std::string& animationPath, Model* model, int n = 0);
	Bone* FindBone(const std::string& name);
	float GetTicksPerSecond() const;
	float GetDuration() const;
	const AssimpNodeData& GetRootNode();
	const std::map<std::string, BoneInfo>& GetBoneIDMap();

private:
	void SetupBones(const aiAnimation* animation, Model& model);
	void ReadHeirarchyData(AssimpNodeData& dest, const aiNode* src);

	float m_Duration;
	int m_TicksPerSecond;
	std::vector<Bone> m_Bones;
	AssimpNodeData m_RootNode;
	std::map<std::string, BoneInfo> m_BoneInfoMap;
};
