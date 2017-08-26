// player.h

#ifndef _PLAYER_
#define _PLAYER_

#include <hand.h>

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
    
    std::shared_ptr<Hand> checkHands();
};

#endif