#include <vector>
#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>
#include <iostream>

Deck::Deck(){
    std::cout << "Deck constructor" << std::endl;
    card = new Card(5);
    for(int i=0; i<=52; ++i){
        cards.push_back(new Card(i));
    }
}

Deck::~Deck(){
    delete card;
    for(int i=0; i<=52; ++i){
        delete cards[i];
    }
}

void Deck::print(){
    for(int i=0; i<=52; ++i){
        std::cout 
            << "[" << i << "]"
            << cards[i]->getSuit() << ":" 
            << cards[i]->getRank() 
            << std::endl;
    }
}

int Deck::getCardNumber(){
    return this->card->getNumber();
}