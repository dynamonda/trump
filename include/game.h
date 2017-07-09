// game.h

#ifndef _GAME_
#define _GAME_

class Game{
private:
    bool gameEndFlag;
    std::unique_ptr<Deck> deck;

public:
    Game();
    ~Game();

    bool setup();
    void update();
    bool isEnd();
};

#endif