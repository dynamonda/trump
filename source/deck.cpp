#include <vector>
#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>
#include <iostream>
#include <utility>

Deck::Deck(){
    for(int i=0; i<=52; ++i){
        cards.push_back(new Card(i));
    }
    std::cout 
        << "Deck constructor [" << cards.size() << "]" 
        << std::endl;
}

Deck::~Deck(){
    for(int i=0; i<cards.size(); ++i){
        delete cards[i];
    }
}

void Deck::print(){
    std::swap(cards[10], cards[20]);
    for(int i=0; i<cards.size(); ++i){
        std::cout 
            << "[" << i << "]"
            << cards[i]->getSuit() << ":" 
            << cards[i]->getRank() 
            << std::endl;
    }
}