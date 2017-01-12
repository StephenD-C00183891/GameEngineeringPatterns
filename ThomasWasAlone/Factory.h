#pragma once

#include "Character.h"

class Factory {
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};

class CharacterFactory : public Factory {
public:
	Character* CreatePlayer() {
		return new Player;
	}
	Character* CreateOpponents() {
		return new Boss;
	}
};