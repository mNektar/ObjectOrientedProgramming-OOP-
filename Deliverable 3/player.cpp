#include <sstream>
#include <iostream>
#include "player.h"

using namespace std;

Player::Player(int id)
{
    this->id = id;
    money = 1500;
    location = 0;

    if (id == 0)
        name = "Player 1";
    else if (id == 1)
        name = "Player 2";
}

void Player::setSpaces(Space** spaces)
{
    this->spaces = spaces;
}

void Player::setLocation(int spaceNum)
{
    location = spaceNum;
}

string Player::getName()
{
    return name;
}

void Player::giveMoneyToPlayer(int amount)
{
    money = money + amount;
}

int Player::getMoney()
{
    return money;
}

void Player::takeMoneyFromPlayer(int amount)
{
    money = money - amount;
}

int Player::getLocation()
{
    return location;
}

bool Player::ownsProperty(int inputIndex)
{
    return spaces[inputIndex]->ownerIs(this);
}

bool Player::ownsProperty(Space* space)
{
    return space->ownerIs(this);
}

int Player::getNumberOfRailRoadsOwned()
{
    int numberOfRailRoads = 0;
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(RailRoadType) && ownsProperty(spaces[i]))
            numberOfRailRoads++;
    }
    return numberOfRailRoads;
}

int Player::getNumberOfUtilitiesOwned()
{
    int numberOfUtilities = 0;
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(UtilityType) && ownsProperty(spaces[i]))
            numberOfUtilities++;
    }
    return numberOfUtilities;
}

bool Player::decideBuy(Space* space)
{
    if (space->typeIs(PropertyType) && getMoney() > 5 * ((Property*)space)->getBuyingCost())
        return true;
    else if (space->typeIs(RailRoadType) && getMoney() > 5 * ((RailRoad*)space)->getBuyingCost())
        return true;
    else if (space->typeIs(UtilityType) && getMoney() > 5 * ((Utility*)space)->getBuyingCost())
        return true;
    else
        return false;
}

int Player::decideUpgrade()
{
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(PropertyType) && canUpgrade((Property*)spaces[i]) && getMoney() > 5 * ((Property*)spaces[i])->getUpgradeCost())
        {
            return i;
        }
    }
    return -1;
}

bool Player::canBuy(Property* property)
{
    if (!ownsProperty(property->getId()) && property->ownerIs(0) && money >= property->getBuyingCost()) return true;
    else return false;
}

bool Player::canBuy(RailRoad* railroad)
{
    if (!ownsProperty(railroad->getId()) && railroad->ownerIs(0) && money >= railroad->getBuyingCost()) return true;
    else return false;
}

bool Player::canBuy(Utility* utility)
{
    if (!ownsProperty(utility->getId()) && utility->ownerIs(0) && money >= utility->getBuyingCost()) return true;
    else return false;
}

bool Player::canUpgrade(Property* property)
{
    for( int i = 0; i < 40 ; i++)
        if(((Property*)spaces[i])->typeIs(PropertyType))
            if(((Property*)spaces[i])->getCategory() == property->getCategory() && !ownsProperty(((Property*)spaces[i]))) return false;
    if(property->ownerIs(this) &&  money >= property->getUpgradeCost() &&  property->getNumberOfHouses() < 5) return true;
    else return false;
}

void Player::buy(Space* space)
{
    space->setOwner(this);
}

void Player::upgrade(Property* space)
{
    space->addHouse();
}
