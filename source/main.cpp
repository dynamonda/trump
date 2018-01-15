// main.cpp

#include <iostream>
#include <vector>

#include "card.h"
#include "game.h"

int main(int argc, char *argv[]){
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->setup();
	
	while(game->isEnd() == false){
		game->update();
	}

	return 0;
}
