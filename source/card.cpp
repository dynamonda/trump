#include <card.h>

Card::Card(int num){
    this->keyNumber = num;
}

Card::~Card(){

}

int Card::getNumber(){
    return this->keyNumber;
}