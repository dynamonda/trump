// game.h

#ifndef _GAME_
#define _GAME_

class Deck;
class Player;
class Card;

class Game{
private:
    bool gameEndFlag;
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Player> player;
    std::vector< std::unique_ptr<Player> > players;

public:
    Game();
    ~Game();

    bool setup();
    void update();


    bool isEnd();
};

#endif