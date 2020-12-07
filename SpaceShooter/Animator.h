#pragma once

class Animator {
public:
	struct Animation {
		std::string m_Name;
		std::string m_Filepath;
		std::string m_TextureName;
		std::vector<sf::IntRect> m_Frames;
		sf::Time m_Duration;
		bool m_Looping;


		Animation(const std::string& name, const std::string& filepath, const std::string& textureName,
			const sf::Time& duration, bool looping)
			: m_Name(name), m_Filepath(filepath), m_TextureName(textureName),
			m_Duration(duration), m_Looping(looping) {}

		//Adding horizontal name
		void AddHorizontalFrames(const sf::Vector2i& startFrom,
			const sf::Vector2i& frameSize, unsigned int frames) {

			sf::Vector2i current = startFrom;

			for (unsigned int i = 0; i < frames; i++) {
				m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));

				current.x += frameSize.x;
			}
		}
		void AddVerticalFrames(const sf::Vector2i& startFrom,
			const sf::Vector2i& frameSize, unsigned int frames) {

			sf::Vector2i current = startFrom;

			for (unsigned int i = 0; i < frames; i++) {
				m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));

				current.y += frameSize.y;
			}
		}
	};

private:
	//returns animation with the passed name, or nullptr if not found
	Animator::Animation* FindAnimation(const std::string& name);

	void SwitchAnimation(Animator::Animation* animation);

	sf::Sprite& m_Sprite;
	float m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;


public:

	
	Animator(sf::Sprite& sprite);
	~Animator() {};

	Animator::Animation& CreateAnimation(const std::string& name, const std::string& filepath,
		const std::string& textureName, const sf::Time& duration, bool loop = false);


	void Update(const float& dt);

	bool SwitchAnimation(const std::string& name);


	std::string GetCurrentAnimationName() const ;	

};

