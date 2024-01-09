#include <iostream>

#include "actions.h"
#define LocP players[playerTurn].getLocation()

using namespace std;

int makeMove(Bank &bank, Player players[], int playerTurn, int diceRoll)
{
    // TODO: Implement this function
    players[playerTurn].setLocation(LocP + diceRoll);
    if (LocP >39 ){
        players[playerTurn].setLocation(LocP - 40);
        players[playerTurn].giveMoneyToPlayer(200);
        bank.takeMoneyFromBank(200);
    }
    if (LocP == 30){
        players[playerTurn].setLocation(10);
    }
    return LocP;
}



void makeAction(Bank &bank, Player players[], Space spaces[], int playerTurn, int newSpace)
{
    // TODO: Implement this function
    if (spaces[LocP].getType() == "Tax"){
        players[playerTurn].takeMoneyFromPlayer(spaces[LocP].getTax());
        bank.giveMoneyToFreePark(spaces[LocP].getTax());
        }
    if (LocP == 20){
        players[playerTurn].giveMoneyToPlayer(bank.takeFreeParkMoney());
    }
    if (LocP == 30){
        players[playerTurn].setLocation(10);
        bank.giveMoneyToFreePark(200);
        players[playerTurn].takeMoneyFromPlayer(200);
    }
    if (spaces[LocP].getType() == "Utility"
        || spaces[LocP].getType() == "Property"
        || spaces[LocP].getType() == "RailRoad"){
        if((spaces[LocP].getOwner() == -1) &&
           players[playerTurn].getMoney() >= 5*spaces[LocP].getBuyingCost()){
            spaces[LocP].setOwner(players[playerTurn].getId());
            players[playerTurn].takeMoneyFromPlayer(spaces[LocP].getBuyingCost());
            bank.giveMoneyToBank(spaces[LocP].getBuyingCost());
        }
        else if(spaces[LocP].getOwner() != playerTurn){
            players[playerTurn].takeMoneyFromPlayer(spaces[LocP].getRent());
            players[1 - playerTurn].giveMoneyToPlayer(spaces[LocP].getRent());
        }
    }
    if (LocP == 20){
        players[playerTurn].giveMoneyToPlayer(bank.takeFreeParkMoney());
    }
    if (LocP == 30){
        players[playerTurn].setLocation(10);
        bank.giveMoneyToFreePark(200);
        players[playerTurn].takeMoneyFromPlayer(200);
    }
}

