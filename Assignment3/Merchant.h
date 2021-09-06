/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include <string>
#include "Faction.h"
using namespace std;

class Merchant
{
private:
    Faction* first_faction;
    Faction* second_faction;
    Faction* third_faction;
    int starting_weapon_point;
    int starting_armor_point;
    int revenue;
    int weapon_point;
    int armor_point;
public:
    Merchant(int = 0, int = 0);
    void AssignFactions(Faction*,Faction*,Faction*);
    bool SellWeapons(string,int);
    bool SellArmors(string,int);
    void EndTurn();

    //Getters
    int GetRevenue(){return this->revenue;};
    int GetArmorPoints(){return this->armor_point;};
    int GetWeaponPoints(){return this->weapon_point;};
};
#endif