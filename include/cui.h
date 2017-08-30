// cui.h

#ifndef _CUI_
#define _CUI_

class CUI;

#include "deck.h"
#include "game.h"
#include "player.h"

#include <vector>
#include <stack>
#include <string>

class Command{
public:
    virtual void execute(Game* const game) = 0;
};

class PlayerCommand : public Command{
protected:
    std::shared_ptr<Player> player;
public:
    using Command::execute;
    virtual void execute(const Game &game, const Player &player) = 0;
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

class ChangeCommand : public PlayerCommand{
private:
    std::unique_ptr<std::vector<int>> changeNums;
public:
    ChangeCommand(){};
    ChangeCommand(const std::shared_ptr<Player> &pl);
    void execute(Game* const game);
    void execute(const Game &game, const Player &player);
    void setChangeNum(int num);
};


class Parser{
private:
    std::vector<std::string> split(const std::string &str, char sep);
    std::stack<std::shared_ptr<Command>> commands;

public:
    Parser(std::string command = "", std::shared_ptr<Player> user = nullptr);
    ~Parser();
    void evaluate(Game* const game);
};

class CUI{
private:
    std::shared_ptr<Player> player;

public:
    CUI();
    ~CUI();

    void setPlayer(std::shared_ptr<Player> const player);
    void waitCommand(Game* const game);
};

#endif