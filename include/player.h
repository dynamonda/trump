// player.h

#ifndef _PLAYER_
#define _PLAYER_

#include <memory>
#include <vector>
#include <card.h>

class Player{
private:
    std::vector<std::shared_ptr<Card>> hands;

public:
    Player();
    ~Player();

    void insertCard(std::shared_ptr<Card> card);
    int getHandsSize();
};

#endif