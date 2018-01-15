// player.h

#ifndef TRUMP_INCLUDE_PLAYER_H_
#define TRUMP_INCLUDE_PLAYER_H_

#include "card.h"
#include "hand.h"

#include <string>
#include <memory>
#include <vector>

class Player{
private:
    std::string name;
    int chip;
    std::vector<std::shared_ptr<Card>> hands;

public:
    Player();
    Player(std::string name);
    ~Player();

    std::string getName();
    void insertCard(std::shared_ptr<Card> card);
    int getHandsSize();
    void printHands();

    void discard(int id);
    
    std::shared_ptr<Hand> checkHands();
};

#endif