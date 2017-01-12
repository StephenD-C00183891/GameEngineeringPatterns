#pragma once
#include "DrawAPI.h"

class CharacterB
{
public:
	virtual void Draw() = 0;
};

class PlayerB : public CharacterB
{
public:
	PlayerB(DrawAPI* api) { this->api = api; }
	void Draw() { api->Draw(); }
private:
	DrawAPI* api;
};