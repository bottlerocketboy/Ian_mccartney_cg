#pragma once
#include <string>
#include "SDL.h"

class shipEntity{
public:
	//sets max velocity
	static const int MaxVelocity = 10;
	// init variables
	shipEntity();
	//moves ship
	void moveShip();
	//renders ship
	void renderShip(int mxPos, int myPos, int mxVelo, int myVelo);
	//may want a re-reder func for screen-wrapping like original asteroids
	//
	//void shipScreenWrapControl();
	//Takes key presses and adjusts the ship's velocity
	void handleEvent(SDL_Event& e);
	//
	protected:
	std::string name;
	int mHealth;
	int mxPos;
	int myPos;
	int mxVelo;
	int myVelo;

	SDL_Rect shipRect;

};