#include "ship.h"
#include "GameManager.h"



shipEntity::shipEntity(){
	//init positions and velocity
	mxPos = 300;
	myPos = 300;
	mxVelo = 0;
	myVelo = 0;
	
}


void shipEntity::renderShip(int mxPos, int myPos, int mxVelo, int myVelo){


}
void shipEntity::handleEvent(SDL_Event& e){
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: myVelo -= MaxVelocity; break;
		case SDLK_DOWN: myVelo += MaxVelocity; break;
		case SDLK_LEFT: mxVelo -= MaxVelocity; break;
		case SDLK_RIGHT: mxVelo += MaxVelocity; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: myVelo += MaxVelocity; break;
		case SDLK_DOWN: myVelo -= MaxVelocity; break;
		case SDLK_LEFT: mxVelo += MaxVelocity; break;
		case SDLK_RIGHT: mxVelo -= MaxVelocity; break;
		}
	}
}
void shipEntity::moveShip(){
	mxPos += mxVelo;
	myPos += myVelo;



}