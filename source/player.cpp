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
    chip = 100;
    std::cout << "Player created" << std::endl;
}

Player::Player(std::string name){
    this->name = name;
    chip = 100;
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
    std::cout << "--- " << name << " ---" << std::endl;
    int id = 0;
    for(auto card : hands){
        std::cout << "[" << id << "]:" << card->getInfoString() << std::endl;
        ++id;
    }
}

std::shared_ptr<Hand> Player::checkHands(){
    std::shared_ptr<Hand> hand = std::make_shared<Hand>(hands);
    return hand;
}