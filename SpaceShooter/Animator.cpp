#include "Animator.h"

Animator::Animator(sf::Sprite& sprite)
	: m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr){}

Animator::Animation& Animator::CreateAnimation(const std::string& name, const std::string& filepath, const std::string& textureName, const sf::Time& duration, bool loop) {
	m_Animations.push_back(Animator::Animation(name, filepath, textureName, duration, loop));

	// if we have no other animations use that as current animation
	if (m_CurrentAnimation == nullptr)
		SwitchAnimation(&m_Animations.back());


	return m_Animations.back();
}

void Animator::Update(const float& dt) {
	if (!m_CurrentAnimation)
		return;

	m_CurrentTime += dt;

	//Current animation frame
	float scaledTime = (m_CurrentTime / m_CurrentAnimation->m_Duration.asSeconds());
	int numberOfFrames = m_CurrentAnimation->m_Frames.size();

	//not looping for now 
	int currentFrame = static_cast<int> (scaledTime * numberOfFrames);

	//if looping
	if (m_CurrentAnimation->m_Looping)
		currentFrame %= numberOfFrames;
	else if (currentFrame >= numberOfFrames)
		currentFrame = numberOfFrames - 1;


	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}

bool Animator::SwitchAnimation(const std::string& name) {

	auto animation = FindAnimation(name);
	if (animation) {
		SwitchAnimation(animation);
		return true;
	}
	return false;
}

std::string Animator::GetCurrentAnimationName() const {
	if (m_CurrentAnimation)
		return m_CurrentAnimation->m_Name;
	//no current animation playing
	return "";
}

Animator::Animation* Animator::FindAnimation(const std::string& name)
{
	for (auto it = m_Animations.begin(); it != m_Animations.end(); it++)
		if (it->m_Name == name)
			return &*it;

	return nullptr;
}

void Animator::SwitchAnimation(Animator::Animation* animation) {

	if (animation)
		m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName, animation->m_Filepath));

	m_CurrentAnimation = animation;
	m_CurrentTime = 0; // reset the time;
}
