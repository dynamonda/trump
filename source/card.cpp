#include <card.h>

Card::Card(int num){
    this->number = num;
}

Card::~Card(){

}

int Card::getNumber(){
    return this->number;
}