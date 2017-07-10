#include <iostream>

#include <player.h>

Player::Player(){
    std::cout << "Player created" << std::endl;
}

Player::~Player(){
    
}

int Player::getHandsSize(){
    return hands.size();
}