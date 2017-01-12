#pragma once

#include <iostream>

using namespace std;

class Character {
public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;

};

class Player : public Character {
public:
	void draw() {
		cout << "Draw Player" << endl;
	}
};

class Boss : public Character {
public:
	void draw() {
		cout << "Draw Boss" << endl;
	}
};


