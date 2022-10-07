#include "bone.hpp"

Bone::Bone(
	const std::string& name,
	int ID,
	const aiNodeAnim* channel
): m_Name(name), m_ID(ID), m_LocalTransform(1.0f) {
	this->m_NumPositions = channel->mNumPositionKeys;

	for (int positionIndex = 0; positionIndex < m_NumPositions; ++positionIndex) {
		aiVector3D aiPosition = channel->mPositionKeys[positionIndex].mValue;
		float timeStamp = channel->mPositionKeys[positionIndex].mTime;
		KeyPosition data;
		data.position = AssimpGLMHelpers::GetGLMVec(aiPosition);
		data.timeStamp = timeStamp;
		this->m_Positions.push_back(data);
	}

	this->m_NumRotations = channel->mNumRotationKeys;
	for (int rotationIndex = 0; rotationIndex < m_NumRotations; ++rotationIndex) {
		aiQuaternion aiOrientation = channel->mRotationKeys[rotationIndex].mValue;
		float timeStamp = channel->mRotationKeys[rotationIndex].mTime;
		KeyRotation data;
		data.orientation = AssimpGLMHelpers::GetGLMQuat(aiOrientation);
		data.timeStamp = timeStamp;
		this->m_Rotations.push_back(data);
	}

	this->m_NumScalings = channel->mNumScalingKeys;
	for (int keyIndex = 0; keyIndex < m_NumScalings; ++keyIndex) {
		aiVector3D scale = channel->mScalingKeys[keyIndex].mValue;
		float timeStamp = channel->mScalingKeys[keyIndex].mTime;
		KeyScale data;
		data.scale = AssimpGLMHelpers::GetGLMVec(scale);
		data.timeStamp = timeStamp;
		this->m_Scales.push_back(data);
	}
}

void Bone::Update(float animationTime) {
	glm::mat4 translation = InterpolatePosition(animationTime);
	glm::mat4 rotation = InterpolateRotation(animationTime);
	glm::mat4 scale = InterpolateScaling(animationTime);
	this->m_LocalTransform = translation * rotation * scale;
}

glm::mat4 Bone::GetLocalTransform() const {
	return this->m_LocalTransform;
}

std::string Bone::GetBoneName() const {
	return this->m_Name;
}

int Bone::GetBoneID() const {
	return this->m_ID;
}

int Bone::GetPositionIndex(float animationTime) {
	for (int index = 0; index < this->m_NumPositions - 1; ++index) {
		if (animationTime < this->m_Positions[index + 1].timeStamp) {
			return index;
		}
	}
	assert(0);
}

int Bone::GetRotationIndex(float animationTime) {
	for (int index = 0; index < this->m_NumRotations - 1; ++index) {
		if (animationTime < this->m_Rotations[index + 1].timeStamp) {
			return index;
		}
	}
	assert(0);
}

int Bone::GetScaleIndex(float animationTime) {
	for (int index = 0; index < this->m_NumScalings - 1; ++index) {
		if (animationTime < this->m_Scales[index + 1].timeStamp) {
			return index;
		}
	}
	assert(0);
}

float Bone::GetScaleFactor(float lastTimeStamp, float nextTimeStamp, float animationTime) {
	float scaleFactor = 0.0f;
	float midWayLength = animationTime - lastTimeStamp;
	float framesDiff = nextTimeStamp - lastTimeStamp;
	scaleFactor = midWayLength / framesDiff;
	return scaleFactor;
}

glm::mat4 Bone::InterpolatePosition(float animationTime) {
	if (1 == this->m_NumPositions) {
		return glm::translate(glm::mat4(1.0f), this->m_Positions[0].position);
	}

	int p0Index = this->GetPositionIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = this->GetScaleFactor(this->m_Positions[p0Index].timeStamp, this->m_Positions[p1Index].timeStamp, animationTime);
	glm::vec3 finalPosition = glm::mix(this->m_Positions[p0Index].position, this->m_Positions[p1Index].position, scaleFactor);
	return glm::translate(glm::mat4(1.0f), finalPosition);
}

glm::mat4 Bone::InterpolateRotation(float animationTime) {
	if (1 == this->m_NumRotations) {
		auto rotation = glm::normalize(this->m_Rotations[0].orientation);
		return glm::toMat4(rotation);
	}

	int p0Index = this->GetRotationIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = this->GetScaleFactor(this->m_Rotations[p0Index].timeStamp, this->m_Rotations[p1Index].timeStamp, animationTime);
	glm::quat finalRotation = glm::slerp(this->m_Rotations[p0Index].orientation, this->m_Rotations[p1Index].orientation , scaleFactor);
	finalRotation = glm::normalize(finalRotation);
	return glm::toMat4(finalRotation);
}

glm::mat4 Bone::InterpolateScaling(float animationTime) {
	if (1 == this->m_NumScalings) {
		return glm::scale(glm::mat4(1.0f), this->m_Scales[0].scale);
	}

	int p0Index = this->GetScaleIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = this->GetScaleFactor(this->m_Scales[p0Index].timeStamp, this->m_Scales[p1Index].timeStamp, animationTime);
	glm::vec3 finalScale = glm::mix(this->m_Scales[p0Index].scale, this->m_Scales[p1Index].scale, scaleFactor);
	return glm::scale(glm::mat4(1.0f), finalScale);
}