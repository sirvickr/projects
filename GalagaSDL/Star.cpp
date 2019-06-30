#include "Star.h"

using namespace QuickSDL;

bool Star::sScroll = false;

void Star::Scroll(bool value)
{
	sScroll = value;
}

Star::Star(int layer)
	: Texture("images/stars.png", 0, 0, 4, 4)
{
	mTimer = Timer::Instance();
	int startColor = rand() % 4;
	mClipRect.x = startColor * 4;
	Pos(Vector2(rand() % Graphics::Instance()->SCREEN_WIDTH, rand() % Graphics::Instance()->SCREEN_HEIGHT));
	mFlickerTimer = 0.0f;
	mFlickerSpeed = 0.15f + ((float)rand() / RAND_MAX) * 0.45f;
	
	float invLayer = 1.0f / layer;
	Scale(VEC2_ONE * invLayer);

	mScrollSpeed = 25.0f / layer;
}

Star::~Star()
{
	mTimer = nullptr;
}

void Star::Update()
{
	mFlickerTimer += mTimer->DeltaTime();
	if (mFlickerTimer >= mFlickerSpeed) {
		mVisible = !mVisible;
		mFlickerTimer = 0.0f;
		if (sScroll) {
			ScrollStar();
		}
	}
}

void Star::Render()
{
	if (mVisible) {
		Texture::Render();
	}
}

void Star::ScrollStar()
{
	Translate(VEC2_UP * mScrollSpeed);
	Vector2 pos = Pos(local);
	if (pos.y > Graphics::Instance()->SCREEN_HEIGHT) {
		pos.x = rand() % Graphics::Instance()->SCREEN_WIDTH;
		pos.y = 0.0f;
		Pos(pos);
	}
}
