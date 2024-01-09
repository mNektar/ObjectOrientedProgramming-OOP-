#include <iostream>
#include <sstream>
#include "player.h"

using namespace std;

// TODO: Implement here the methods of Player
Player::Player(int playerId){
    id = playerId;
    stringstream ss;
    ss << (id + 1);
    name = "Player " + ss.str();
    money = 1500;
    location = 0;
}
int Player::getId(){
    return id;
}
int Player::getLocation(){
    return location;
}
string Player::getName(){
    return name;
}
int Player::getMoney(){
    return money;
}
void Player::setLocation(int spaceNum){
    location = spaceNum;
}
void Player::giveMoneyToPlayer(int amount){
    money += amount;
}
void Player::takeMoneyFromPlayer(int amount){
    money -= amount;
}
