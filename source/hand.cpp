#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>

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
    }else if(IsStraight(cardList)){
        this->handName = HandName::STRAIGHT;
    }else if(IsOnePair(cardList)){
        this->handName = HandName::ONE_PAIR;
    }else{
        this->handName = HandName::NO_PAIR;
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
    std::vector<Rank> straightList{
        Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX,
        Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK,
        Rank::QUEEN, Rank::KING, Rank::ACE
    };
    //for(auto itr=straightList.begin(); itr!=straightList.end(); ++itr){
        //std::cout << "LIST:" << (int)(*itr) << std::endl;
    //}
    std::map<Rank, int> cardMap;
    if(IsJoker(cardList)){

    }else{
        for(auto card : cardList){
            int num = cardMap[card->getRank()];
            cardMap[card->getRank()] = ++num;
        }
        /*for(auto itr=cardMap.begin(); itr!=cardMap.end(); ++itr){
            std::cout << "Key:" << (int)(itr->first) <<
                " Value:" << itr->second << std::endl;
        }*/
        int count = 0;
        for(auto itr=straightList.begin(); itr!=straightList.end(); ++itr){
            if(count <= 0){
                if(cardMap[*itr] > 0){
                    ++count;
                }
            } else {
                if(count < 5){
                    count = 0;
                }
            }
        }
        if(count >= 5){
            return true;
        }
    }
    return false;
}

bool Hand::IsThreeOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}

bool Hand::IsTwoPair(std::vector<std::shared_ptr<Card>> cardList){
    return false;
}
    
bool Hand::IsOnePair(std::vector<std::shared_ptr<Card>> cardList){
    if(IsJoker(cardList)){
        return true;
    }else{
        std::map<Rank,int> counter;
        for(auto card : cardList){
            Rank rank = card->getRank();
            if(counter[rank] == 0){
                counter[card->getRank()] += 1;
            }else{
                return true;
            }
        }
    }
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

std::vector<std::shared_ptr<Card>> Hand::copyCardList(std::vector<std::shared_ptr<Card>> cardList){
    std::vector<std::shared_ptr<Card>> list(cardList.size());
    for(auto card: cardList){
        list.push_back(std::make_shared<Card>(card->getNumber()));
    }
    return list;
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