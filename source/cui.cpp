#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

#include <deck.h>
#include <cui.h>
#include <game.h>

void ShowCommand::execute(Game* const game){
    std::cout << "=== show deck list ===" << std::endl;
    game->deck->print();
}

void ExitCommand::execute(Game* const game){
    std::cout << "=== Exit message ===" << std::endl;
    game->setEnd();
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
            if(str == "exit"){
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
    std::cout << "> ";
    std::getline(std::cin, command);
    std::unique_ptr<Parser> parser = std::make_unique<Parser>(command, player);
    parser->evaluate(game);
}