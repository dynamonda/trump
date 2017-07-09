#include <vector>
#include <memory>
#include <iostream>
#include <vector>

#include <deck.h>
#include <player.h>
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

    std::cout << "Setup Success!" << std::endl;

    //Player* player = new Player();
    //delete player;
    //player = nullptr;
    
    //auto player = std::make_shared<Player>();
    //std::cout << player << std::endl;
    
    //players.push_back(player);
    
    return true;
}

void Game::update(){
    std::cout << "Game Update" << std::endl;

    deck->shuffle();
	deck->print();

    gameEndFlag = true;
}

bool Game::isEnd(){
    return gameEndFlag;
}