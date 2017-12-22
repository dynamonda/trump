#include "card.h"
#include "game.h"

#include <iostream>
#include <vector>

int main(int argc, char *argv[]){
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->setup();
	
	while( !(game->isEnd()) ){
		game->update();
	}

	return 0;
}
