#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <card.h>
#include <deck.h>

int main(){
	std::cout << "Hello world" << std::endl;
	Deck *deck = new Deck();
	std::cout << deck->getNumber() << std::endl;
	return 0;
}
