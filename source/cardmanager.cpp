#include <vector>
#include <memory>
#include <iostream>

#include <suit.h>
#include <rank.h>
#include <card.h>
#include <cardmanager.h>

CardManager::CardManager(){
    for(int i=0; i<=52; ++i){
        auto card = std::make_shared<Card>(i);
        cards.push_back(card);
    }

    for(auto c : cards){
        std::cout << c << ":" << c->getInfoString() <<std::endl;
    }
}

CardManager::~CardManager(){

}

