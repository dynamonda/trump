#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <suit.h>
#include <rank.h>
#include <card.h>
#include <game.h>

int main(){
	std::cout << "Hello world" << std::endl;

	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->setup();
	
	while( !(game->isEnd()) ){
		game->update();
	}

	return 0;
}
