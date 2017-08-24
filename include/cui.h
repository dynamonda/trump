// cui.h

#ifndef _CUI_
#define _CUI_

class Game;
class Player;

class Command{
public:
    virtual void execute(Game* const game) = 0;
};

class ShowCommand: public Command{
public:
    ShowCommand(){};
    void execute(Game* const game);
};

class ExitCommand: public Command{
public:
    ExitCommand(){};
    void execute(Game* const game);
};

class Parser{
private:
    std::vector<std::string> split(const std::string &str, char sep);
    std::stack<std::shared_ptr<Command>> commands;

public:
    Parser(std::string command = "");
    ~Parser();
    void evaluate(Game* const game);
};

class CUI{
private:
    std::shared_ptr<Player> player;

public:
    CUI();
    ~CUI();

    void waitCommand(Game* const game);
};

#endif