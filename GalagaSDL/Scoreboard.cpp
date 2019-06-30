#include "Scoreboard.h"

#include <string>

using namespace QuickSDL;

Scoreboard::Scoreboard()
{
	Score(0);
}

Scoreboard::~Scoreboard()
{
	Clear();
}

void Scoreboard::Render()
{
	for (size_t i = 0; i < mScore.size(); ++i) {
		mScore[i]->Render();
	}
}

void Scoreboard::Score(int score)
{
	Clear();
	if (score) {
		std::string s = std::to_string(score);
		int lastIndex = s.length() - 1;
		for (int i = 0; i <= lastIndex; ++i) {
			mScore.push_back(new Texture(s.substr(i, 1), "fonts/emulogic.ttf", 32, { 230, 230, 230 }));
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f * (lastIndex - i), 0.0f));
		}
	}
	else {
		for (int i = 0; i < 2; ++i) {
			mScore.push_back(new Texture("0", "fonts/emulogic.ttf", 32, { 230, 230, 230}));
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f * i, 0.0f));
		}
	}
}

void Scoreboard::Clear()
{
	for (size_t i = 0; i < mScore.size(); ++i) {
		delete mScore[i];
		mScore[i] = nullptr;
	}
	mScore.clear();
}
