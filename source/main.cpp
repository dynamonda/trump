#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deck.h>

int main(){
	std::cout << "Hello world" << std::endl;
	Deck *deck = new Deck();
	std::cout << deck->getCardNumber() << std::endl;
	delete deck;
	return 0;
}
