// player.h

#ifndef _PLAYER_
#define _PLAYER_

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