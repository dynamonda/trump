#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

#include <cui.h>
#include <deck.h>
#include <player.h>
#include <rank.h>
#include <suit.h>
#include <hand.h>
#include <card.h>
#include <game.h>

Game::Game(){
    cui = std::make_unique<CUI>();
    gameEndFlag = false;
    std::cout << "Game Created" << std::endl;
}

Game::~Game(){
}

bool Game::setup(){
	std::cout << "Setup Start" << std::endl;
    
    deck = std::make_unique<Deck>();
    
    players.push_back(std::make_shared<Player>("Taro"));
    //players.push_back(std::make_shared<Player>("Hanako"));
    std::cout << "Player Num: " << players.size() << std::endl;
    cui->setPlayer(players[0]);

    deck->shuffle();

    for(auto pl : players){
        while(pl->getHandsSize() < 5){
            auto card = deck->draw();
            pl->insertCard(card);
        }

        //pl->printHands();

        auto hand = pl->checkHands();
        if(hand != nullptr){
            std::cout << "Hand : "<< hand->ToString() << std::endl;
        } else {
            std::cout << "Hand : NULL" << std::endl;
        }
    }

    return true;
}

void Game::update(){
    std::cout << "Game Update" << std::endl;
    players[0]->printHands();
    cui->waitCommand(this);   
}

bool Game::isEnd(){
    return gameEndFlag;
}

void Game::setEnd(){
    gameEndFlag = true;
}

std::shared_ptr<Player> Game::getPlayer(int id){
    if(players[id] != nullptr){
        return players[id];
    }else{
        return nullptr;
    }
};