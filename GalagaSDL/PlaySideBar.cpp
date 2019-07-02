#include "PlaySideBar.h"
#include "Timer.h"
#include "AudioManager.h"
#include "Texture.h"
#include "Scoreboard.h"

using namespace QuickSDL;

PlaySideBar::PlaySideBar()
{
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mBackground = new Texture("images/black.png");
	mBackground->Parent(this);
	mBackground->Pos(Vector2(45.0f, 380.0f));
	mBackground->Scale(Vector2(3.0f, 10.0f));

	mHighLabel = new Texture("HIGH", "fonts/emulogic.ttf", 32, { 150, 0, 0 });
	mHighLabel->Parent(this);
	mHighLabel->Pos(Vector2(-25.0f, 0.0f));

	mScoreLabel = new Texture("SCORE", "fonts/emulogic.ttf", 32, { 150, 0, 0 });
	mScoreLabel->Parent(this);
	mScoreLabel->Pos(Vector2(25.0f, 32.0f));

	mHighScore = new Scoreboard();
	mHighScore->Parent(this);
	mHighScore->Pos(Vector2(90.0f, 64.0f));

	mPlayerOneLabel = new Texture("1UP", "fonts/emulogic.ttf", 32, { 150, 0, 0 });
	mPlayerOneLabel->Parent(this);
	mPlayerOneLabel->Pos(Vector2(-45.0f, 160.0f));

	mPlayerOneScore = new Scoreboard();
	mPlayerOneScore->Parent(this);
	mPlayerOneScore->Pos(Vector2(90.0f, 192.0f));

	mBlinkTimer = 0.0f;
	mBlinkInterval = 0.5f;
	mPlayerOneLabelVisible = true;

	mShips = new GameEntity();
	mShips->Parent(this);
	mShips->Pos(Vector2(-40.0f, 450.0f));

	for (int i = 0; i < MAX_SHIP_TEXTURES; ++i) {
		mShipsTextures[i] = new Texture("images/playership.png");
		mShipsTextures[i]->Parent(mShips);
		mShipsTextures[i]->Pos(Vector2(70.0f * (i % 3), 70.0f * (i / 3)));
	}

	mTotalShipsLabel = new Scoreboard();
	mTotalShipsLabel->Parent(mShips);
	mTotalShipsLabel->Pos(Vector2(152.0f, 85.0f));

	mTotalShips = 0;
}

PlaySideBar::~PlaySideBar()
{
	mTimer = nullptr;
	mAudio = nullptr;

	delete mBackground;
	mBackground = nullptr;

	delete mHighLabel;
	mHighLabel = nullptr;
	delete mScoreLabel;
	mScoreLabel = nullptr;
	delete mHighScore;
	mHighScore = nullptr;

	delete mPlayerOneLabel;
	mPlayerOneLabel = nullptr;
	delete mPlayerOneScore;
	mPlayerOneScore = nullptr;

	delete mShips;
	mShips = nullptr;

	for (int i = 0; i < MAX_SHIP_TEXTURES; ++i) {
		delete mShipsTextures[i];
		mShipsTextures[i] = nullptr;
	}

	delete mTotalShipsLabel;
	mTotalShipsLabel = nullptr;
}

void PlaySideBar::Update()
{
	mBlinkTimer += mTimer->DeltaTime();
	if (mBlinkTimer >= mBlinkInterval) {
		mPlayerOneLabelVisible = !mPlayerOneLabelVisible;
		mBlinkTimer = 0.0f;
	}
}

void PlaySideBar::Render()
{
	mBackground->Render();
	mHighLabel->Render();
	mScoreLabel->Render();
	mHighScore->Render();
	mPlayerOneScore->Render();

	if(mPlayerOneLabelVisible) {
		mPlayerOneLabel->Render();
	}

	for (int i = 0; i < MAX_SHIP_TEXTURES && i < mTotalShips; ++i) {
		mShipsTextures[i]->Render();
	}

	if (mTotalShips > MAX_SHIP_TEXTURES) {
		mTotalShipsLabel->Render();
	}
}

void PlaySideBar::SetHighScore(int score)
{
	mHighScore->Score(score);
}

void PlaySideBar::SetPlayerOneScore(int score)
{
	mPlayerOneScore->Score(score);
}

void PlaySideBar::SetShips(int value)
{
	mTotalShips = value;
	if (mTotalShips > MAX_SHIP_TEXTURES) {
		mTotalShipsLabel->Score(mTotalShips);
	}
}
