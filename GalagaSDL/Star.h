#pragma once

#include "Timer.h"
#include "Texture.h"

class Star : public QuickSDL::Texture
{
public:
	static void Scroll(bool value);

	Star(int layer);
	~Star();

	void Update() override;
	void Render() override;

private:
	static bool sScroll;

	QuickSDL::Timer* mTimer;

	bool mVisible;
	float mFlickerTimer;
	float mFlickerSpeed;

	float mScrollSpeed;

private:
	void ScrollStar();
};
