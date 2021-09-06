/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Elves.h"
using namespace std;

Elves::Elves(string name, int units, int ap, int hp, int regen) : Faction(name, units, ap, hp, regen) {}

void Elves::PerformAttack()
{
    int buffedAP = (attack_points * 150) / 100;//If the enemy is the dwarfs Elves will have attack power buff.
    if (first_enemy->IsAlive() && second_enemy->IsAlive())//If the both enemies are alive
    {
        int army_for_orcs = (number_of_units * 60) / 100;//send the %60 of army to the orcs
        int army_for_dwarves = number_of_units - army_for_orcs;//send the remaining troops to the dwarfs

        if (first_enemy->getName() == "Orcs" && second_enemy->getName() == "Dwarves")//Since first_enemy and second_enemy assignment could be vary we should check this
        {
            first_enemy->ReceiveAttack(name, attack_points, army_for_orcs);
            second_enemy->ReceiveAttack(name, buffedAP, army_for_dwarves);
        }
        else
        {
            first_enemy->ReceiveAttack(name, buffedAP, army_for_dwarves);
            second_enemy->ReceiveAttack(name, attack_points, army_for_orcs);
        }
    }
    else if (first_enemy->IsAlive())//If only the first enemy is alive
    {
        if (first_enemy->getName() == "Dwarves")//We should check whether this enemy is dwarfs, if they are dwarfs elves will have attack power buff
            first_enemy->ReceiveAttack(name, buffedAP, number_of_units);
        else
            first_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
    else if (second_enemy->IsAlive())//If only the second enemy is alive
    {
        if (second_enemy->getName() == "Dwarves")//We should check whether this enemy is dwarfs, if they are dwarfs elves will have attack power buff
            second_enemy->ReceiveAttack(name, buffedAP, number_of_units);
        else
            second_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
}

void Elves::ReceiveAttack(string assaulter, int assaulter_AP, int assaulter_Army)
{
    if (assaulter == "Orcs")//If the assaulter is orcs we will have sickness against them and they will have buff against us. and increased to 125%.
    {
        assaulter_AP = (assaulter_AP * 125) / 100;
    }
    else if (assaulter == "Dwarves")//If the assaulter is dwarfs it will shrink to 75%.
    {
        assaulter_AP = (assaulter_AP * 75) / 100;
    }

    int enemyForce = assaulter_AP * assaulter_Army;
    int causalities = enemyForce / health_points;
    int remainingForces = number_of_units - causalities;
    setNumOfUnits(remainingForces);
}

int Elves::PurchaseWeapons(int purchased_weapons)
{
    int new_ap = attack_points + (purchased_weapons * 2);//For each purchased weapon attack power increased by double.
    setAP(new_ap);
    return 15 * purchased_weapons;//For each purchased weapon 15 gold will be paid
}

int Elves::PurchaseArmors(int purchased_armors)
{
    int new_hp = health_points + (purchased_armors * 4);//For each purchased armor health points increased by quadruple.
    setHP(new_hp);
    total_health = number_of_units * health_points;//update the total health
    return 5 * purchased_armors;//For each purchased armor 5 golds will be paid
}

void Elves::Print()
{
    cout << "\"You cannot reach our elegance.\"" << endl;
    Faction::Print();
}