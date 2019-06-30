#pragma once

namespace QuickSDL {
	class InputManager;
}

class BackgroundStars;
class StartScreen;

class ScreenManager
{
public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();

private:
	enum SCREENS { start, play };

	static ScreenManager* sInstance;

	QuickSDL::InputManager* mInput;

	BackgroundStars* mBackgroundStars;
	StartScreen* mStartScreen;

	SCREENS mCurrentScreen;
};

