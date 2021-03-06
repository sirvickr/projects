#pragma once

#include "GameEntity.h"

namespace QuickSDL {
	class Timer;
	class AudioManager;
	class Texture;
}

class Scoreboard;

class PlaySideBar : public QuickSDL::GameEntity
{
public:
	PlaySideBar();
	~PlaySideBar();

	void Update() override;
	void Render() override;

	void SetHighScore(int score);
	void SetPlayerOneScore(int score);
	void SetShips(int value);

private:
	QuickSDL::Timer* mTimer;
	QuickSDL::AudioManager* mAudio;
	
	QuickSDL::Texture* mBackground;
	
	QuickSDL::Texture* mHighLabel;
	QuickSDL::Texture* mScoreLabel;
	Scoreboard* mHighScore;

	QuickSDL::Texture* mPlayerOneLabel;
	Scoreboard* mPlayerOneScore;
	float mBlinkTimer;
	float mBlinkInterval;
	bool mPlayerOneLabelVisible;

	static const int MAX_SHIP_TEXTURES = 5;
	QuickSDL::GameEntity* mShips;
	QuickSDL::Texture* mShipsTextures[MAX_SHIP_TEXTURES];
	Scoreboard* mTotalShipsLabel;
	int mTotalShips;
};

