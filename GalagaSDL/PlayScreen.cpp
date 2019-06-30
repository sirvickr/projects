#include "PlayScreen.h"
#include "InputManager.h"
#include "Timer.h"
#include "BackgroundStars.h"
#include "PlaySideBar.h"

using namespace QuickSDL;

PlayScreen::PlayScreen()
{
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	mStars = BackgroundStars::Instance();
	
	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.85, 
		Graphics::Instance()->SCREEN_HEIGHT * 0.05));
	mSideBar->SetHighScore(30000);
	mSideBar->SetPlayerOneScore(10000);
}

PlayScreen::~PlayScreen()
{
	mTimer = nullptr;
	mInput = nullptr;

	mStars = nullptr;

	delete mSideBar;
	mSideBar = nullptr;
}

void PlayScreen::Update()
{
	mSideBar->Update();
}

void PlayScreen::Render()
{
	mSideBar->Render();
}
