#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <deck.h>
#include <player.h>
#include <rank.h>
#include <suit.h>
#include <card.h>
#include <game.h>

Game::Game(){
    gameEndFlag = false;
    std::cout << "Game Created" << std::endl;
}

Game::~Game(){

}

bool Game::setup(){
	std::cout << "Setup Start" << std::endl;
    
    deck = std::make_unique<Deck>();
    
    players.push_back(std::make_unique<Player>("Taro"));
    players.push_back(std::make_unique<Player>("Hanako"));
    std::cout << "Player Num: " << players.size() << std::endl;
    std::cout << "Setup Success!" << std::endl;
    return true;
}

void Game::update(){
    std::cout << "Game Update" << std::endl;

    deck->shuffle();
    deck->print();

    while(players[0]->getHandsSize() < 5){
        auto card = deck->draw();
        players[0]->insertCard(card);
    }

    std::cout << players[0]->getHandsSize() << std::endl;
    players[0]->printHands();
    gameEndFlag = true;
}

bool Game::isEnd(){
    return gameEndFlag;
}