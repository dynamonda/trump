#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include <suit.h>
#include <rank.h>
#include <card.h>
#include <hand.h>
#include <player.h>

Player::Player(){
    std::cout << "Player created" << std::endl;
}

Player::Player(std::string name){
    name = name;
    std::cout << "Player created : " << name << std::endl;
}

Player::~Player(){
    
}

void Player::insertCard(std::shared_ptr<Card> card){
    hands.push_back(card);
}

int Player::getHandsSize(){
    return hands.size();
}

void Player::printHands(){
    for(auto card : hands){
        std::cout << card->getInfoString() << std::endl;
    }
}

std::shared_ptr<Hand> Player::checkHands(){
    return nullptr;
}