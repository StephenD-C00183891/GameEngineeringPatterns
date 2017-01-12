#pragma once

#include <iostream>

using namespace std;

class DrawAPI
{
public:
	virtual void Draw() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void Draw() {
		cout << "Draw Impl" << endl; }
};