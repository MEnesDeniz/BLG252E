/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef DWARVES_H
#define DWARVES_H
#include <iostream>
#include <string>
#include "Faction.h"
using namespace std;

class Dwarves : public Faction
{
public:
    Dwarves(string = " ", int = 0, int = 0, int = 0, int = 0);
    void PerformAttack();
    void ReceiveAttack(string, int, int);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};
#endif