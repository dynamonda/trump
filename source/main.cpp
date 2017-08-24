#include <iostream>
#include <vector>

#include <suit.h>
#include <rank.h>
#include <card.h>
#include <game.h>

int main(){
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->setup();
	
	while( !(game->isEnd()) ){
		game->update();
	}

	return 0;
}
