/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Orcs.h"
using namespace std;

Orcs::Orcs(string name, int units, int ap, int hp, int regen) : Faction(name, units, ap, hp, regen) {}//Constructor

void Orcs::PerformAttack()
{

    if (first_enemy->IsAlive() && second_enemy->IsAlive())//If both enemies are alive
    {
        int army_for_elves = (number_of_units * 7) / 10;//Send the %70 of your army to the Elves
        int army_for_dwarves = number_of_units - army_for_elves;//Send the remaining troops to the Dwarfs

        if (first_enemy->getName() == "Elves" && second_enemy->getName() == "Dwarves")//Since first_enemy and second_enemy assignment could be vary we should check this
        {
            first_enemy->ReceiveAttack(name, attack_points, army_for_elves);
            second_enemy->ReceiveAttack(name, attack_points, army_for_dwarves);
        }
        else
        {
            first_enemy->ReceiveAttack(name, attack_points, army_for_dwarves);
            second_enemy->ReceiveAttack(name, attack_points, army_for_elves);
        }
    }
    else if (first_enemy->IsAlive())//If only the first enemy is alive send your all trops
    {
        first_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
    else if (second_enemy->IsAlive())//If only the second enemy is alive send your all troops
    {
        second_enemy->ReceiveAttack(name, attack_points, number_of_units);
    }
}

void Orcs::ReceiveAttack(string assaulter, int assaulter_AP, int assaulter_Army)
{
    if (assaulter == "Elves")//If you receive attack from elves, they will have debuff in their Attack power and their attack power will reduced by %25
    {
        assaulter_AP = (assaulter_AP * 75) / 100;
    }
    else if (assaulter == "Dwarves")//If you receive attack from elves, they will have debuff in their Attack power and their attack power will reduced by %20
    {
        assaulter_AP = (assaulter_AP * 80) / 100;
    }

    int enemyForce = assaulter_AP * assaulter_Army;
    int causalities = enemyForce / health_points;
    int remainingForces = number_of_units - causalities;
    setNumOfUnits(remainingForces);
}

int Orcs::PurchaseWeapons(int purchased_weapons)
{
    int new_ap = attack_points + (purchased_weapons * 2);//If you purchase weapons for each weapon your Attack power will increased as double for per unit of weapon
    setAP(new_ap);
    return 20 * purchased_weapons;//for each weapon orcs will pay 20 golds
}

int Orcs::PurchaseArmors(int purchased_armors)
{
    int new_hp = health_points + (purchased_armors * 3);//If you purchase armors for each armor your Health point will increased as triple for per unit of armor
    setHP(new_hp);
    total_health = number_of_units * health_points;//update the total health
    return purchased_armors;//for each armors orcs will pay 1 gold
}

void Orcs::Print()
{
    cout << "\"Stop running, you'll only die tired!\"" << endl;
    Faction::Print();
}