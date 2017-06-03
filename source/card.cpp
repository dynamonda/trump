#include <suit.h>
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