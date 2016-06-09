#include "GameManager.h"

int main( int argc, char* args[] )
{
	GameManager gameManager;

	if(gameManager.Init()){
		while (!sdlQuit){
			sdlInit.Update();
		
		}//while close
	}

	gameManager.Cleanup();

	return 0;
}

//TIP: to revert changes ::
// 1.) git add -A
//2.) git stash

//To get back stash
//3.) git stash apply