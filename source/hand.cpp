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
    }else if(IsStraightFlush(cardList)){
        this->handName = HandName::STRAIGHT_FLUSH;
    }else if(IsFourOfaKind(cardList)){
        this->handName = HandName::FOUR_OF_A_KIND;
    }else if(IsFullHouse(cardList)){
        this->handName = HandName::FULL_HOUSE;
    }else if(IsFlush(cardList)){
        this->handName = HandName::FLUSH;
    }else if(IsStraight(cardList)){
        this->handName = HandName::STRAIGHT;
    }else if(IsThreeOfaKind(cardList)){
        this->handName = HandName::THREE_OF_A_KIND;
    }else if(IsTwoPair(cardList)){
        this->handName = HandName::TWO_PAIR;
    }else if(IsOnePair(cardList)){
        this->handName = HandName::ONE_PAIR;
    }else{
        this->handName = HandName::NO_PAIR;
    }
}

Hand::~Hand(){

}

bool Hand::IsRoyalFlush(std::vector<std::shared_ptr<Card>> cardList){
    if(IsFlush(cardList)){
        std::map<Rank, int> cardMap;
        for(auto card: cardList){
            int num = cardMap[card->getRank()];
            cardMap[card->getRank()] = ++num;
        }
        int count = cardMap[Rank::TEN] + cardMap[Rank::JACK] + cardMap[Rank::QUEEN]
            + cardMap[Rank::KING] + cardMap[Rank::ACE];
        if(IsJoker(cardList)){
            if(count == 4){
                return true;
            }
        }else{
            if(count == 5){
                return true;
            }
        }
    }
    return false;
}

bool Hand::IsStraightFlush(std::vector<std::shared_ptr<Card>> cardList){
    if(IsFlush(cardList) && IsStraight(cardList)){
        return true;
    }
    return false;
}

bool Hand::IsFourOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    std::map<Rank, int> cardMap;
    for(auto card: cardList){
        int num = cardMap[card->getRank()];
        cardMap[card->getRank()] = ++num;
    }
    if(IsJoker(cardList)){
        int count = 0;
        for(auto i = cardMap.begin(); i!=cardMap.end(); i++){
            if(i->second == 3){
                ++count;
            }
        }
        if(count == 1){
            return true;
        }
    }else{
        int count = 0;
        for(auto i = cardMap.begin(); i!=cardMap.end(); i++){
            if(i->second == 4){
                ++count;
            }
        }
        if(count == 1){
            return true;
        }
    }
    return false;
}

bool Hand::IsFullHouse(std::vector<std::shared_ptr<Card>> cardList){
    std::map<Rank, int> cardMap;
    for(auto card: cardList){
        int num = cardMap[card->getRank()];
        cardMap[card->getRank()] = ++num;
    }
    if(IsJoker(cardList)){
        int count = 0;
        for(auto i = cardMap.begin(); i!=cardMap.end(); i++){
            if(i->second == 2){
                ++count;
            }
        }
        if(count == 2){
            return true;
        }else{
            return false;
        }
    }else{
        int three_count = 0;
        int two_count = 0;
        for(auto i = cardMap.begin(); i!=cardMap.end(); ++i){
            if(i->second == 3){
                ++three_count;
            }else if(i->second == 2){
                ++two_count;
            }
        }
        if((three_count==1)&&(two_count==1)){
            return true;
        }
    }
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

    std::map<Rank, int> cardMap;
    for(auto card : cardList){
        int num = cardMap[card->getRank()];
        cardMap[card->getRank()] = ++num;
    }

    bool useSkip = false;
    if(IsJoker(cardList)){
        useSkip = true;
    }
    for(auto itr=straightList.begin(); itr!=straightList.end()-4; ++itr){
        int count = 0;
        for(int j=0; j<5; ++j){
            if(cardMap[*(itr+j)] > 0){
                ++count;
            }
        }
        if(useSkip && count==4){
            return true;
        }else if(count == 5){
            return true;
        }
    }
    return false;
}

bool Hand::IsThreeOfaKind(std::vector<std::shared_ptr<Card>> cardList){
    std::map<Rank,int> counter;
    for(auto card: cardList){
        Rank rank = card->getRank();
        counter[rank] += 1;
    }
    int threshold = 3;
    if(counter[Rank::JOKER] >= 1){
        threshold -= 1;
    }
    for(auto i = counter.begin(); i != counter.end(); ++i){
        if(i->second >= threshold){
            return true;
        }
    }
    return false;
}

bool Hand::IsTwoPair(std::vector<std::shared_ptr<Card>> cardList){
    std::map<Rank,int> counter;
    for(auto card : cardList){
        Rank rank = card->getRank();
        counter[rank] += 1;
    }
    int two_count = 0;
    for(auto i = counter.begin(); i != counter.end(); ++i){
        if(i->second >= 2){
            two_count += 1;
        }
    }
    if(two_count >=2 ){
        return true;
    }else{
        return false;
    }
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
        case HandName::STRAIGHT_FLUSH:
            return "Straight Flush";
        case HandName::FOUR_OF_A_KIND:
            return "Four of a kind";
        case HandName::FULL_HOUSE:
            return "Full House";
        case HandName::FLUSH:
            return "Flush";
        case HandName::STRAIGHT:
            return "Straight";
        case HandName::THREE_OF_A_KIND:
            return "Three of a kind";
        case HandName::TWO_PAIR:
            return "Two Pair";
        case HandName::ONE_PAIR:
            return "One Pair";
        case HandName::NO_PAIR:
            return "No Pair";
        default:
            return "null";
    }
}