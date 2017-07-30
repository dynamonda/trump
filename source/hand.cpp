#include <string>
#include <memory>
#include <vector>

#include <suit.h>
#include <rank.h>
#include <card.h>
#include <hand.h>

Hand::Hand(){
    handName = HandName::NO_PAIR;
}

Hand::Hand(std::vector<std::shared_ptr<Card>> cardList){
    if(IsRoyalFlush(cardList)){
        this->handName = HandName::ROYAL_FLUSH;
    }else{
        this->handName = HandName::ONE_PAIR;
    }
}

Hand::~Hand(){

}

bool Hand::IsRoyalFlush(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsStraightFlush(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsFourOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsFullHouse(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsFlush(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsStraight(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsThreeOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool IsTwoPair(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}
    
bool IsOnePair(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

std::string Hand::ToString(){
    switch(this->handName){
        case HandName::ROYAL_FLUSH:
            return "Royal Flush";
        case HandName::ONE_PAIR:
            return "One Pair";
        case HandName::NO_PAIR:
            return "No Pair";
        default:
            return "null";
    }
}