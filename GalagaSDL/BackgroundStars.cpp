#include "BackgroundStars.h"

BackgroundStars* BackgroundStars::sInstance = nullptr;

BackgroundStars* BackgroundStars::BackgroundStars::Instance()
{
	if(!sInstance)
		sInstance = new BackgroundStars();
	return sInstance;
}

void BackgroundStars::Release()
{
	sInstance = nullptr;
}

void BackgroundStars::Scroll(bool value)
{
	Star::Scroll(value);
}

BackgroundStars::BackgroundStars()
{
	for (int i = 0; i < LAYER_COUNT; ++i) {
		mLayers[i] = new StarLayer(i);
	}
}

BackgroundStars::~BackgroundStars()
{
	for (int i = 0; i < LAYER_COUNT; ++i) {
		delete mLayers[i];
		mLayers[i] = nullptr;
	}
}

void BackgroundStars::Update()
{
	for (int i = 0; i < LAYER_COUNT; ++i) {
		mLayers[i]->Update();
	}
}

void BackgroundStars::Render()
{
	for (int i = 0; i < LAYER_COUNT; ++i) {
		mLayers[i]->Render();
	}
}
