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
        return Suit(keyNumber / 14);
    }
}

Rank Card::getRank(){
    if(keyNumber==0){
        return Rank::JOKER;
    } else {
        int num = this->keyNumber;
        while(num > 13){
            num = num - 13;
        }
        return Rank(num);
    }
}