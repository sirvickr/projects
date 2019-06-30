#include "StartScreen.h"
#include "BackgroundStars.h"
#include "Scoreboard.h"

#include <iostream>

using namespace QuickSDL;

StartScreen::StartScreen()
{
	std::cout << "StartScreen:ctor" << std::endl;
	float width = static_cast<float>(Graphics::Instance()->SCREEN_WIDTH);
	float height = static_cast<float>(Graphics::Instance()->SCREEN_HEIGHT);

	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	// Top bar entities
	mTopBar = new GameEntity(Vector2(width * 0.5f, 80.0f));
	mPlayerOne = new Texture("1UP", "fonts/emulogic.ttf", 32, {200, 0, 0});
	mHiScore = new Texture("HI-SCORE", "fonts/emulogic.ttf", 32, { 200, 0, 0 });
	mPlayerTwo = new Texture("2UP", "fonts/emulogic.ttf", 32, { 200, 0, 0 });
	mPlayerOneScore = new Scoreboard();
	mTopScore = new Scoreboard();
	mPlayerTwoScore = new Scoreboard();

	mPlayerOne->Parent(mTopBar);
	mHiScore->Parent(mTopBar);
	mPlayerTwo->Parent(mTopBar);
	mPlayerOneScore->Parent(mTopBar);
	mTopScore->Parent(mTopBar);
	mPlayerTwoScore->Parent(mTopBar);

	mPlayerOne->Pos(Vector2(-width * 0.35f, 0.0f));
	mHiScore->Pos(Vector2(-30.0f, 0.0f));
	mPlayerTwo->Pos(Vector2(width * 0.2f, 0.0f));
	mPlayerOneScore->Pos(Vector2(-width * 0.23f, 40.0f));
	mTopScore->Pos(Vector2(width * 0.05f, 40.0f));
	mPlayerTwoScore->Pos(Vector2(width * 0.32f, 40.0f));

	mTopScore->Score(30000);

	mTopBar->Parent(this);

	// Logo entities
	mLogo = new Texture("images/logo.png", 0, 0, 360, 180);
	mLogo->Pos(Vector2(width * 0.5f, height * 0.32f));
	mLogo->Parent(this);

	// Play mode entities
	mPlayerModes = new GameEntity(Vector2(width * 0.5f, height * 0.53f));
	mOnePlayerMode = new Texture("1 Player", "fonts/emulogic.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("2 Players", "fonts/emulogic.ttf", 32, { 230, 230, 230 });
	mCursor = new Texture("images/cursor.png");

	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mCursor->Parent(mPlayerModes);

	mOnePlayerMode->Pos(Vector2(-20.0f, -35.0f));
	mTwoPlayerMode->Pos(Vector2(0.0f, 35.0f));
	mCursor->Pos(Vector2(-175.0f, -35.0f));

	mPlayerModes->Parent(this);

	mCursorStartPos = mCursor->Pos(local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;

	// Bottom bar entities
	mBotBar = new GameEntity(Vector2(width * 0.5f, height * 0.7f));
	mNamco = new Texture("namcot", "fonts/namco__.ttf", 36, { 200, 0, 0 });
	mDates = new Texture("1981 1985 NAMCO LTD.", "fonts/emulogic.ttf", 32, { 230, 230, 230 });
	mRights = new Texture("ALL RIGHTS RESERVED", "fonts/emulogic.ttf", 32, { 230, 230, 230 });

	mNamco->Parent(mBotBar);
	mDates->Parent(mBotBar);
	mRights->Parent(mBotBar);

	mNamco->Pos(VEC2_ZERO);
	mDates->Pos(Vector2(0.0f, 90.0f));
	mRights->Pos(Vector2(0.0f, 170.0f));

	mBotBar->Parent(this);

	// Screen animation variables
	mAnimationStartPos = Vector2(0.0f, height);
	mAnimationEndPos = VEC2_ZERO;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Pos(mAnimationStartPos);

	mStars = BackgroundStars::Instance();
	mStars->Scroll(true);
}

StartScreen::~StartScreen()
{
	std::cout << "StartScreen:dtor" << std::endl;
	delete mTopBar;
	mTopBar = NULL;
	delete mPlayerOne;
	mPlayerOne = NULL;
	delete mHiScore;
	mHiScore = NULL;
	delete mPlayerTwo;
	mPlayerTwo = NULL;
	delete mPlayerOneScore;
	mPlayerOneScore = NULL;
	delete mTopScore;
	mTopScore = NULL;
	delete mPlayerTwoScore;
	mPlayerTwoScore = NULL;

	delete mLogo;
	mLogo = NULL;

	delete mPlayerModes;
	mPlayerModes = NULL;
	delete mOnePlayerMode;
	mOnePlayerMode = NULL;
	delete mTwoPlayerMode;
	mTwoPlayerMode = NULL;
	delete mCursor;
	mCursor = NULL;

	delete mBotBar;
	mBotBar = NULL;
	delete mNamco;
	mNamco = NULL;
	delete mDates;
	mDates = NULL;
	delete mRights;
	mRights = NULL;
}

void StartScreen::Update()
{
	if (mAnimationDone) {
		if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
			ChangeSelectedMode(1);
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
			ChangeSelectedMode(-1);
		}
	}
	else {
		mAnimationTimer += mTimer->DeltaTime();
		Pos(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
			mStars->Scroll(false);
		}
		if (mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP)) {
			mAnimationTimer = mAnimationTotalTime;
		}
	}
}

void StartScreen::Render()
{
	mPlayerOne->Render();
	mHiScore->Render();
	mPlayerTwo->Render();
	mPlayerOneScore->Render();
	mTopScore->Render();
	mPlayerTwoScore->Render();

	mLogo->Render();

	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();

	mBotBar->Render();
	mNamco->Render();
	mDates->Render();
	mRights->Render();
}

void StartScreen::ChangeSelectedMode(int change)
{
	mSelectedMode += change;
	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}
	mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
}
