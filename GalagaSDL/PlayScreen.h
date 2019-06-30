#pragma once

#include "GameEntity.h"

namespace QuickSDL {
	class Timer;
	class InputManager;
}

class BackgroundStars;
class PlaySideBar;

class PlayScreen : public QuickSDL::GameEntity
{
public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;

private:
	QuickSDL::Timer* mTimer;
	QuickSDL::InputManager* mInput;
	BackgroundStars* mStars;
	PlaySideBar* mSideBar;
};

