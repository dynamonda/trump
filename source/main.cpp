#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>
#include <cardmanager.h>

int main(){
	std::cout << "Hello world" << std::endl;
	CardManager *cardManager = new CardManager();
	Deck *deck = new Deck();

	deck->shuffle();
	deck->print();

	delete cardManager;
	delete deck;
	return 0;
}
