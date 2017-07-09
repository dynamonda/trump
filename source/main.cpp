#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>
#include <cardmanager.h>
#include <game.h>

int main(){
	std::cout << "Hello world" << std::endl;

	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->setup();
	
	while( !(game->isEnd()) ){
		game->update();
	}

	std::unique_ptr<Deck> deck = std::make_unique<Deck>();

	deck->shuffle();
	deck->print();

	return 0;
}
