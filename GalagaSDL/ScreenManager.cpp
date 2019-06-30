#include "ScreenManager.h"
#include "InputManager.h"
#include "BackgroundStars.h"
#include "StartScreen.h"
#include "PlayScreen.h"

using namespace QuickSDL;

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::ScreenManager::Instance()
{
	if (!sInstance)
		sInstance = new ScreenManager();
	return sInstance;
}

void ScreenManager::Release()
{
	sInstance = nullptr;
}

ScreenManager::ScreenManager()
{
	mInput = InputManager::Instance();
	mBackgroundStars = BackgroundStars::Instance();
	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();

	mCurrentScreen = start;
}

ScreenManager::~ScreenManager()
{
	mInput = nullptr;

	BackgroundStars::Release();
	mBackgroundStars = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;

	delete mPlayScreen;
	mPlayScreen = nullptr;
}

void ScreenManager::Update()
{
	mBackgroundStars->Update();
	switch (mCurrentScreen) {
	case start:
		mStartScreen->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			mCurrentScreen = play;
			mStartScreen->ResetAnmation();
		}
		break;
	case play:
		mPlayScreen->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = start;
		}
		break;
	}
}

void ScreenManager::Render()
{
	mBackgroundStars->Render();
	switch (mCurrentScreen) {
	case start:
		mStartScreen->Render();
		break;
	case play:
		mPlayScreen->Render();
		break;
	}
}
