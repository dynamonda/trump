#include <vector>
#include <deck.h>
#include <suit.h>
#include <card.h>
#include <iostream>

Deck::Deck(){
    std::cout << "Deck constructor" << std::endl;
    card = new Card(5);
    std::cout << "test" << std::endl;
    for(int i=0; i<5; ++i){
        cards.push_back(new Card(i));
    }
}

Deck::~Deck(){
    delete card;
    for(int i=0; i<5; ++i){
        delete cards[i];
    }
}

void Deck::print(){
    for(int i=0; i<5; ++i){
        std::cout << cards[i]->getNumber() << std::endl;
    }
}

int Deck::getCardNumber(){
    return this->card->getNumber();
}