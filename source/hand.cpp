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

}

Hand::~Hand(){

}

std::string Hand::ToString(){
    switch(this->handName){
        case HandName::NO_PAIR:
            return "No Pair";
        default:
            return "null";
    }
}