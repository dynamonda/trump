// game.h

#ifndef _GAME_
#define _GAME_

class Game{
private:
    bool gameEndFlag;

public:
    Game();
    ~Game();

    void update();
    bool isEnd();
};

#endif