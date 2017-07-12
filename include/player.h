// player.h

#ifndef _PLAYER_
#define _PLAYER_

class Player{
private:
    std::string name;
    std::vector<std::shared_ptr<Card>> hands;

public:
    Player();
    Player(std::string name);
    ~Player();

    void insertCard(std::shared_ptr<Card> card);
    int getHandsSize();
    void printHands();
};

#endif