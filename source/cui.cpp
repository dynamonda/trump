// cui.cpp

#include "cui.h"

#include <algorithm>
#include <iostream>
#include <sstream>

void ShowCommand::execute(Game* const game){
    std::cout << "=== show deck list ===" << std::endl;
    game->deck->print();
}

void ExitCommand::execute(Game* const game){
    std::cout << "=== Exit message ===" << std::endl;
    game->setEnd();
}

ChangeCommand::ChangeCommand(const std::shared_ptr<Player> &pl){
    this->player = pl;
    this->changeNums = std::make_unique<std::vector<int>>();
}

void ChangeCommand::execute(Game* const game){
    std::cout << "Change Command execute:" << std::endl;
    std::reverse(this->changeNums->begin(), this->changeNums->end());
    for(int i=0; i<this->changeNums->size(); ++i){
        int num = this->changeNums->at(i);
        std::cout << num << " ";
        this->player->discard(num);
    }
    for(int i=0; i<this->changeNums->size(); ++i){
        auto card = game->deck->draw();
        this->player->insertCard(card);
    }
    std::cout << std::endl;
};

void ChangeCommand::execute(const Game &game, const Player &player){
    std::cout << std::endl;
}

void ChangeCommand::setChangeNum(int num){
    if ((num < 5) 
            && (std::count(changeNums->begin(), changeNums->end(), num) <= 0)){
        this->changeNums->push_back(num);
        std::sort(changeNums->begin(), changeNums->end());
    }
}

Parser::Parser(std::string command, std::shared_ptr<Player> user){
    auto splitCommand = split(command, ' ');
    if(splitCommand.size() > 0){
        auto str = splitCommand[0];
        if(user == nullptr){
            if(str == "player"){

            }else if(str == "show"){
                if(splitCommand.size() > 1){
                    if(splitCommand[1] == "deck"){
                        commands.push(std::make_shared<ShowCommand>());
                    }
                }else{

                }
            }else if(str == "help"){
                std::cout << "=== Help message ===" << std::endl;
                std::cout << " show deck : print deck list" << std::endl;
                std::cout << " help : print help message" << std::endl;
                std::cout << " exit : end this game" << std::endl;
                std::cout << std::endl;
            }else if(str == "exit"){
                commands.push(std::make_shared<ExitCommand>());
            }else{
                std::cout << "Error, not exist command: " << str << std::endl;
            }
        }else{
            if(str == "change"){
                if(splitCommand.size() > 1){
                    auto changeCommand = std::make_shared<ChangeCommand>(user);
                    for(int index = 1; index < splitCommand.size(); ++index){
                        try{
                            int changeNum = std::stoi(splitCommand[index]);
                            changeCommand->setChangeNum(changeNum);
                        }catch(std::invalid_argument arg){
                            std::cout << "数値を入力してください: " << splitCommand[index] << std::endl;
                        }catch(...){
                            std::cout << "エラーが発生しました" << std::endl;
                        }
                    }
                    commands.push(changeCommand);
                }
            }else if(str == "exit"){
                commands.push(std::make_shared<ExitCommand>());
            }else{
                std::cout << "Player command: " << str << std::endl;
            }
        }
    }
}

Parser::~Parser(){

}

std::vector<std::string> Parser::split(const std::string &str, char sep){
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while(std::getline(ss, buffer, sep)){
        v.push_back(buffer);
    }
    return v;
}

void Parser::evaluate(Game* const game){
    while(commands.size() > 0){
        auto command = commands.top();
        commands.pop();
        command->execute(game);
    }
}

CUI::CUI(){
    this->player = nullptr;
    std::cout << "CUI Created" << std::endl;
}

CUI::~CUI(){

}

void CUI::setPlayer(std::shared_ptr<Player> const player){
    this->player = player;
};

void CUI::waitCommand(Game* const game){
    std::string command;
    if(player==nullptr){
        std::cout << "> ";
    }else{
        std::cout << player->getName() << " > ";
    }
    std::getline(std::cin, command);
    std::unique_ptr<Parser> parser = std::make_unique<Parser>(command, player);
    parser->evaluate(game);
}