#include <string>
#include <hand.h>

Hand::Hand(){
    handName = HandName::NO_PAIR;
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