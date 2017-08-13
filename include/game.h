// game.h

#ifndef _GAME_
#define _GAME_

class Deck;
class Player;
class Card;

class Game{
private:
    std::unique_ptr<CUI> cui;
    
    bool gameEndFlag;
    std::unique_ptr<Deck> deck;
    std::vector< std::shared_ptr<Player> > players;

public:
    Game();
    ~Game();

    bool setup();
    void update();

    bool isEnd();
};

#endif