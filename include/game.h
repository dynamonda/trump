// game.h

#ifndef _GAME_
#define _GAME_

class Deck;
class Player;
class Card;
class CUI;

class Game{
private:
    std::unique_ptr<CUI> cui;
    
    bool gameEndFlag;
    std::vector< std::shared_ptr<Player> > players;

public:
    Game();
    ~Game();

    std::unique_ptr<Deck> deck;

    bool setup();
    void update();

    bool isEnd();
    void setEnd();
};

#endif