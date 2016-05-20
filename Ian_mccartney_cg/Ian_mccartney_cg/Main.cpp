#include "GameManager.h"

extern bool sdlQuit;
int main( int argc, char* args[] )
{
	GameManager gameManager;

	if(gameManager.Init()){
		while (!sdlQuit){
			gameManager.Update();
		}//while close
	}

	gameManager.Cleanup();

	return 0;
}