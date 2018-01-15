// game.h

#ifndef TRUMP_INCLUDE_GAME_H_
#define TRUMP_INCLUDE_GAME_H_

class Game;

#include <memory>
#include <vector>

#include "cui.h"
#include "deck.h"
#include "player.h"

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