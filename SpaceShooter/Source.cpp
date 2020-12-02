#include "Game.h"
#include "vld.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main() {

	Game game;
	game.run();


	_CrtDumpMemoryLeaks();
	return 0;
}