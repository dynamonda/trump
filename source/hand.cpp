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
    }else if(IsFlush(cardList)){
        this->handName = HandName::FLUSH;
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

bool Hand::IsFourOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsFullHouse(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsFlush(std::vector<std::shared_ptr<Card>> cardList){
    Suit checkSuit = Suit::Null;
    for(auto card : cardList){
        if(checkSuit == Suit::Null){
            if(card->getSuit() != Suit::Joker){
                checkSuit = card->getSuit();
            }
        }else{
            Suit suit = card->getSuit();
            if((checkSuit != suit) && (suit != Suit::Joker)){
                return false;
            }
        }
    }
    return true;
}

bool Hand::IsStraight(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsThreeOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsTwoPair(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}
    
bool Hand::IsOnePair(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsJoker(std::vector<std::shared_ptr<Card>> cardList){
    bool result = false;
    for(auto card : cardList){
        if(card->getNumber() == 0){
            result = true;
        }
    }
    return result;
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