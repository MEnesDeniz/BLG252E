/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Merchant.h"
using namespace std;

Merchant::Merchant(int starting_weapon_point, int starting_armor_point)//Constructor
{
    this->starting_armor_point = starting_weapon_point;
    this->starting_weapon_point = starting_armor_point;
    this->weapon_point = this->starting_armor_point;
    this->armor_point = this->starting_armor_point;
    this->revenue = 0;
    this->first_faction = NULL;
    this->second_faction = NULL;
    this->third_faction = NULL;
}

void Merchant::AssignFactions(Faction *f1, Faction *f2, Faction *f3)//Assign the factions
{
    first_faction = f1;
    second_faction = f2;
    third_faction = f3;
}

bool Merchant::SellWeapons(string faction_name, int weapons_to_sell)
{
    Faction *buyer_faction;//To find the buyer faction name look for each faction
    if (faction_name == first_faction->getName())
    {
        buyer_faction = first_faction;
    }
    else if (faction_name == second_faction->getName())
    {
        buyer_faction = second_faction;
    }
    else if (faction_name == third_faction->getName())
    {
        buyer_faction = third_faction;
    }

    if (buyer_faction->IsAlive() == false)//If the buyer faction is dead you cannot sell
    {
        cout << "The faction you want to sell weapons is dead!" << endl;
        return false;
    }

    if (weapons_to_sell > weapon_point)//If you try to sell more than you own it is not possible
    {
        cout << "You try to sell more weapons than you have in possession." << endl;
        return false;
    }

    weapon_point -= weapons_to_sell;//Decreased the inventory after selling
    int sales_revenue = buyer_faction->PurchaseWeapons(weapons_to_sell);//Acquire sales revenue
    revenue += sales_revenue;
    cout << "Weapons sold!" << endl;
    return true;
}

bool Merchant::SellArmors(string faction_name, int armors_to_sell)
{
    Faction *buyer_faction;//To find the buyer faction name look for each faction
    if (faction_name == first_faction->getName())
    {
        buyer_faction = first_faction;
    }
    else if (faction_name == second_faction->getName())
    {
        buyer_faction = second_faction;
    }
    else if (faction_name == third_faction->getName())
    {
        buyer_faction = third_faction;
    }

    if (buyer_faction->IsAlive() == false)//If the buyer faction is dead you cannot sell
    {
        cout << "The faction you want to sell armors is dead!" << endl;
        return false;
    }

    if (armors_to_sell > armor_point)//If you try to sell more than you own it is not possible
    {
        cout << "You try to sell more armors than you have in possession." << endl;
        return false;
    }

    armor_point -= armors_to_sell;//Decreased the inventory after selling
    int sales_revenue = buyer_faction->PurchaseArmors(armors_to_sell);//Acquire sales revenue
    revenue += sales_revenue;
    cout << "Armors sold!" << endl;
    return true;
}

void Merchant::EndTurn()//For each turn start refresh your inventory.
{
    weapon_point = starting_weapon_point;
    armor_point = starting_armor_point;
}