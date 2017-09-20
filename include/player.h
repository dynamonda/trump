// player.h

#ifndef _PLAYER_
#define _PLAYER_

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

    void draw();
    void discard(int id);
    
    std::shared_ptr<Hand> checkHands();
};

#endif