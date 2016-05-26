#include "ship.h"
#include "GameManager.h"


shipEntity::shipEntity(){
	//init positions and velocity
	mxPos = 300;
	myPos = 300;
	mxVelo = 0;
	myVelo = 0;
}

////need fuction for keypress events/////////////////
//void shipEntity::moveShip(**){    **possibly put my enum fr keypresses in here for a parameter
//	if (key press){
//		switch (keycode enum){
//			case up: -myVelo; break;
//			case down: +myVelo; break;
//			case left: -mxVelo; break;
//			case right: +mxVelo; break;
//
//			}
//
//		}
//
//	}
///////////////////////////////////////////
//for wrapping action controls
//void shipEntity::shipScreenWrapControl(){
//
//
//}
