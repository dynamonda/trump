// game.h

#ifndef _GAME_
#define _GAME_

class Game{
private:
    bool gameEndFlag;

public:
    Game();
    ~Game();

    bool setup();
    void update();
    bool isEnd();
};

#endif