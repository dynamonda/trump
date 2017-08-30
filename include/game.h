// game.h

#ifndef _GAME_
#define _GAME_

class Game;

#include "cui.h"
#include "deck.h"
#include "player.h"

#include <memory>
#include <vector>

class Game{
private:
    std::unique_ptr<CUI> cui;
    
    bool gameEndFlag;
    std::vector<std::shared_ptr<Player>> players;

public:
    Game();
    ~Game();

    std::unique_ptr<Deck> deck;

    bool setup();
    void update();

    bool isEnd();
    void setEnd();

    std::shared_ptr<Player> getPlayer(int id);
};

#endif