#include "animation.hpp"

Animation::Animation() = default;

Animation::Animation(const std::string& animationPath, Model* model, int n) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(animationPath, aiProcess_Triangulate);
	assert(scene && scene->mRootNode);
	auto animation = scene->mAnimations[n];
	this->m_Duration = animation->mDuration;
	this->m_TicksPerSecond = animation->mTicksPerSecond;
	ReadHeirarchyData(m_RootNode, scene->mRootNode);
	SetupBones(animation, *model);
	this->m_Bones.reserve(100);
}

Animation::~Animation() {}

float Animation::GetTicksPerSecond() const {
	return this->m_TicksPerSecond;
}

float Animation::GetDuration() const {
	return this->m_Duration;
}

const AssimpNodeData& Animation::GetRootNode() {
	return this->m_RootNode;
}

const std::map<std::string, BoneInfo>& Animation::GetBoneIDMap() {
	return this->m_BoneInfoMap;
}

Bone* Animation::FindBone(const std::string& name) {
	auto iter = std::find_if(
		this->m_Bones.begin(),
		this->m_Bones.end(),
		[&](const Bone& Bone) {
			return Bone.GetBoneName() == name;
		}
	);
	if (iter == this->m_Bones.end()) { 
		return nullptr;
	} else {
		return &(*iter);
	}
}

void Animation::SetupBones(const aiAnimation* animation, Model& model) {
	int size = animation->mNumChannels;

	std::map<std::string, BoneInfo> boneInfoMap = model.GetOffsetMatMap();
	int boneCount = model.GetBoneCount();

	for (int i = 0; i < size; i++) {
		auto channel = animation->mChannels[i];
		std::string boneName = channel->mNodeName.data;

		if (boneInfoMap.find(boneName) == boneInfoMap.end()) {
			boneInfoMap[boneName].id = boneCount;
			boneCount++;
		}
		this->m_Bones.push_back(Bone(channel->mNodeName.data, boneInfoMap[channel->mNodeName.data].id, channel));
	}

	this->m_BoneInfoMap = boneInfoMap;
}

void Animation::ReadHeirarchyData(AssimpNodeData& dest, const aiNode* src) {
	assert(src);

	dest.name = src->mName.data;
	dest.transformation = AssimpGLMHelpers::ConvertMatrixToGLMFormat(src->mTransformation);
	dest.childrenCount = src->mNumChildren;
	dest.children.reserve(src->mNumChildren);

	for (unsigned int i = 0; i < src->mNumChildren; i++) {
		AssimpNodeData newData;
		this->ReadHeirarchyData(newData, src->mChildren[i]);
		dest.children.push_back(newData);
	}
}