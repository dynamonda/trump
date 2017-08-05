// cui.h

#ifndef _CUI_
#define _CUI_

class Game;

class Parser{
private:
public:
    Parser(std::string command = "");
    ~Parser();
};

class CUI{
private:

public:
    CUI();
    ~CUI();

    void waitCommand(Game* const game);
};

#endif