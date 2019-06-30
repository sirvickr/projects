#pragma once

#include "AnimatedTexture.h"
#include "InputManager.h"

class BackgroundStars;
class Scoreboard;

class StartScreen :
	public QuickSDL::GameEntity
{
public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;

	void ResetAnmation();
	int SelectedMode();
	void ChangeSelectedMode(int change);

private:
	QuickSDL::Timer* mTimer;
	QuickSDL::InputManager* mInput;
	// Top bar entities
	QuickSDL::GameEntity* mTopBar;
	QuickSDL::Texture* mPlayerOne;
	QuickSDL::Texture* mHiScore;
	QuickSDL::Texture* mPlayerTwo;
	Scoreboard* mPlayerOneScore;
	Scoreboard* mTopScore;
	Scoreboard* mPlayerTwoScore;

	// Logo entities
	QuickSDL::Texture* mLogo;
	//QuickSDL::AnimatedTexture* mAnimatedLogo;

	// Play mode entities
	QuickSDL::GameEntity* mPlayerModes;
	QuickSDL::Texture* mOnePlayerMode;
	QuickSDL::Texture* mTwoPlayerMode;
	QuickSDL::Texture* mCursor;
	QuickSDL::Vector2 mCursorStartPos;
	QuickSDL::Vector2 mCursorOffset;
	int mSelectedMode;

	// Bottom bar entities
	QuickSDL::GameEntity* mBotBar;
	QuickSDL::Texture* mNamco;
	QuickSDL::Texture* mDates;
	QuickSDL::Texture* mRights;

	// Screen animation variables
	QuickSDL::Vector2 mAnimationStartPos;
	QuickSDL::Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	BackgroundStars* mStars;
};

