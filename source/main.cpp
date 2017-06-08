#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>

int main(){
	std::cout << "Hello world" << std::endl;
	Deck *deck = new Deck();
	//std::cout << deck->getCardNumber() << std::endl;

	Card *joker = new Card(0);
	Card *card = new Card(1);

	std::cout << joker->getSuit() << std::endl;
	std::cout << card->getSuit() << std::endl;

	deck->print();

	delete card;
	delete joker;
	delete deck;
	return 0;
}
