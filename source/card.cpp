#include <suit.h>
#include <rank.h>
#include <card.h>

Card::Card(int num){
    this->keyNumber = num;
}

Card::~Card(){

}

int Card::getNumber(){
    return this->keyNumber;
}

Suit Card::getSuit(){
    if(keyNumber==0){
        return Suit::Joker;
    } else {
        return Suit::Diamonds;
    }
}

Rank Card::getRank(){
    if(keyNumber==0){
        return Rank::JOKER;
    } else {
        return Rank(keyNumber % 13);
    }
}