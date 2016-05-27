#pragma once
#include <string>

class shipEntity{
public:
	//sets max velocity
	static const int MaxVelocity = 10;
	// init variables
	shipEntity();
	//moves ship
	void moveShip();
	//renders ship
	void renderShip();
	//may want a re-reder func for screen-wrapping like original asteroids
	//
	//void shipScreenWrapControl();

	//enum KeyPressEvent{
	//	KEY_PRESS_SURFACE_DEFAULT,
	//	KEY_PRESS_SURFACE_UP,
	//	KEY_PRESS_SURFACE_DOWN,
	//	KEY_PRESS_SURFACE_LEFT,
	//	KEY_PRESS_SURFACE_RIGHT,
	//	KEY_PRESS_SURFACE_TOTAL
	//};

protected:
	std::string name;
	int mHealth;
	int mxPos;
	int myPos;
	int mxVelo;
	int myVelo;



};