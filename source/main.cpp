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

int main(){
	std::cout << "Hello world" << std::endl;
	CardManager *cardManager = new CardManager();
	std::unique_ptr<Deck> deck = std::make_unique<Deck>();

	//deck->shuffle();
	deck->print();

	delete cardManager;
	return 0;
}
