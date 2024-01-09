#include "card.h"

Card::Card(int id, string text){
    this->id = id;
    this->text = text;
}

int Card::getId(){
    return id;
}

string Card::getText(){
    return text;
}

CardMove::CardMove(int id, string text, int location) : Card(id, text){
    this->location = location;
}

void CardMove::cardAction(Bank *bank, Player *player){
    player->setLocation(location);
}

CardMoney::CardMoney(int id, string text, int amount) : Card(id, text){
    this->amount = amount;
}

void CardMoney::cardAction(Bank *bank, Player *player){
    bank->takeMoneyFromBank(amount);
    player->giveMoneyToPlayer(amount);
}
