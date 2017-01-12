#include "stdafx.h"

#include <iostream>
using namespace std;

//Abstract Factory
#include "Character.h"
#include "Factory.h"

//Bridge Pattern 1
#include "BridgeCharacter.h"

//Bridge Pattern 2
#include "CharacterB.h"
#include "DrawAPI.h"

//Proxy Implementation
#include "Graphic_Proxy.h"

#include "LTimer.h"
#include "Game.h"


const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}


bool Game::init() {	

	//Abstract Factory
	Factory* factory = new CharacterFactory;
	vector<Character*> characters;

	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	//Bridge Pattern 1
	HandleToCharacter handle;
	handle->Print();

	//Bridge Pattern 2
	DrawAPI* api = new DrawImpl();
	CharacterB* characterB = new PlayerB(api);
	characterB->Draw();
	cin.get();

	//Proxy Implementation
	GraphicProxy gp;
	gp.Draw();

	return true;

}


void Game::destroy()
{
	gameObjects.clear();
	renderer.destroy();
}

//** calls update on all game entities*/
void Game::update()
{
	//unsigned int currentTime = LTimer::gameTime();//millis since game started
	//unsigned int deltaTime = currentTime - lastTime;//time since last update

	//save the curent time for next frame
	//lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{
	//renderer.clear(Colour(0,0,0));// prepare for new frame

	renderer.present();// display the new frame (swap buffers)
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate

	int frameNum = 0;
	while (!quit) { //game loop
		capTimer.start();

		inputManager.ProcessInput();

		if(!pause) //in pause mode don't bother updateing
			update();
		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(EventListener::Event evt) {

	if (evt == EventListener::Event::PAUSE) {
		pause = !pause;
	}
	
	if (evt == EventListener::Event::QUIT) {
		quit=true;
	}

}
