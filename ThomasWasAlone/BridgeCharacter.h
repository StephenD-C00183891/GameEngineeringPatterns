#pragma once

#include <iostream>
using namespace std;

class BridgeCharacter
{
public:
	BridgeCharacter() {}
	void Print() { cout << "Printing Character" << endl; }
};

class HandleToCharacter
{
public:
	HandleToCharacter() : character(new BridgeCharacter()) { }
	BridgeCharacter* operator->() { return character; } //overload->
private:
	BridgeCharacter* character;
};