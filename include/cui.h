// cui.h

#ifndef _CUI_
#define _CUI_

class Game;

class Expression{
public:
    virtual void interpret(std::stack<int> stack);
};

class Parser{
private:
    std::vector<std::string> split(const std::string &str, char sep);

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