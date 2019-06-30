#pragma once

#include "Texture.h"

#include <vector>

class Scoreboard : public QuickSDL::GameEntity
{
public:
	Scoreboard();
	~Scoreboard();

	void Render() override;

	void Score(int score);

private:
	void Clear();

private:
	std::vector<QuickSDL::Texture*> mScore;
};

