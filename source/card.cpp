#include "card.h"

#include <cmath>

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
        return Suit(std::ceil(keyNumber / 14.0));
    }
}

std::string Card::getSuitString(){
    switch(getSuit()){
        case Suit::Joker:
            return "Joker"; break;
        case Suit::Spades:
            return "Spades"; break;
        case Suit::Hearts:
            return "Hearts"; break;
        case Suit::Diamonds:
            return "Diamonds"; break;
        case Suit::Clubs:
            return "Culubs"; break;
        default:
            return "NotDefined";
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

std::string Card::getInfoString(){
    std::string str = "";
    str += std::to_string(int(getRank()));
    
    switch(getSuit()){
        case Suit::Joker:
            str += " Joker"; break;
        case Suit::Spades:
            str += " Spades"; break;
        case Suit::Hearts:
            str += " Hearts"; break;
        case Suit::Diamonds:
            str += " Diamonds"; break;
        case Suit::Clubs:
            str += " Culubs"; break;
        default:
            str += " NotDefined"; break;
    }
    return str;
}