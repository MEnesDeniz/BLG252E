/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Dwarves.h"
using namespace std;

Dwarves::Dwarves(string name, int units, int ap, int hp, int regen) : Faction(name, units, ap, hp, regen) {}

void Dwarves::PerformAttack()
{

    if (first_enemy->IsAlive() && second_enemy->IsAlive())//If both enemies are alive
    {
        int army_half_floor = number_of_units / 2;//Send the half your army to the first enemy but in the case of odd number you will round the number to floor, e.g. 25/2=12 man will sent to first enemy
        int army_half_ceil = number_of_units - army_half_floor;//Send the remaining troops to the second enemy

        first_enemy->ReceiveAttack(name, attack_points, army_half_floor);
        second_enemy->ReceiveAttack(name, attack_points, army_half_ceil);
    }
    else if (first_enemy->IsAlive())//If only first enemy alive send your all trops to them
    {
        first_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
    else if (second_enemy->IsAlive())//If only second enemy alive send your all trops to them
    {
        second_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
}

void Dwarves::ReceiveAttack(string assaulter, int assaulter_AP, int assaulter_Army)
{
    int enemyForce = assaulter_AP * assaulter_Army;
    int causalities = enemyForce / health_points;
    int remainingForces = number_of_units - causalities;
    setNumOfUnits(remainingForces);
}

int Dwarves::PurchaseWeapons(int purchased_weapons)
{
    int new_ap = attack_points + purchased_weapons;//For each purchased weapon attack power increased by 1.
    setAP(new_ap);
    return 10 * purchased_weapons;//for each purchased weapon pays 10 gold
}

int Dwarves::PurchaseArmors(int purchased_armors)
{
    int new_hp = health_points + (purchased_armors * 2);//For each purchased armor health points increased by double.
    setHP(new_hp);
    total_health = number_of_units * health_points;//update the total health
    return 3 * purchased_armors;//for each purchased armor pays 3 gold
}

void Dwarves::Print()
{
    cout << "\"Taste the power of our axes!\"" << endl;
    Faction::Print();
}