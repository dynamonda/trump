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

	deck->shuffle(100);
	deck->print();
	
	//deck->shuffle(10);

	delete deck;
	return 0;
}
