#include <vector>
#include <memory>
#include <iostream>

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
    std::cout << "Setup Success!" << std::endl;

	deck = std::make_unique<Deck>();
    player = std::make_unique<Player>();

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