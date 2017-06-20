#include <vector>
#include <deck.h>
#include <suit.h>
#include <rank.h>
#include <card.h>
#include <iostream>
#include <utility>
#include <random>

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
        cards[i] = nullptr;
    }
}

void Deck::print(){
    for(int i=0; i<cards.size(); ++i){
        int rank = int(cards[i]->getRank());
        std::cout 
            << "[" << i << "]"
            << cards[i]->getSuit() << ":" 
            << rank
            << std::endl;
    }
}

void Deck::shuffle(int times){
    std::cout << "Shuffle " << times << std::endl;
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> randCardNum(0, cards.size()-1);
    for(int i=0; i<times; ++i){
        int swp1 = randCardNum(mt);
        int swp2 = randCardNum(mt);
        std::swap(cards[swp1], cards[swp2]);
    }
}