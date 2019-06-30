#include "ScreenManager.h"
#include "InputManager.h"
#include "BackgroundStars.h"
#include "StartScreen.h"

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

	mCurrentScreen = start;
}

ScreenManager::~ScreenManager()
{
	mInput = nullptr;

	BackgroundStars::Release();
	mBackgroundStars = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;
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
	}
}
