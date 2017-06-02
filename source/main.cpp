#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <card.h>

int main(){
	std::cout << "Hello world" << std::endl;
	Card card(3);
	std::cout << card.num() << std::endl;
	return 0;
}
