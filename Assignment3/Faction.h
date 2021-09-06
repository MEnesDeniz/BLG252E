/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef FACTION_H
#define FACTION_H
#include <iostream>
#include <string>
using namespace std;

class Faction//Abstract Class since it has a pure virtual functions
{
protected:
    string name;
    Faction *first_enemy;
    Faction *second_enemy;
    int number_of_units;
    int attack_points;
    int health_points;
    int regen_num;
    int total_health;
    bool is_alive;

public:
    Faction(string = " ", int = 0, int = 0, int = 0, int = 0);
    void AssignEnemies(Faction* , Faction*);
    virtual void Print();
    void EndTurn();

    //Getters
    bool IsAlive(){return this->is_alive;};
    Faction* getEnemyFirst(){return this->first_enemy;};
    Faction* getEnemySecond(){return this->second_enemy;};
    int getUnitNum(){return this->number_of_units;};
    int getAP(){return this-> attack_points;};
    int getHP(){return this->health_points;};
    string getName(){return this->name;};
    //Setters
    void setAlive(bool alive){this->is_alive = alive;};
    void setNumOfUnits(int num_of_units){this->number_of_units = num_of_units;};
    void setAP(int ap){this->attack_points = ap;};
    void setHP(int hp){this->health_points = hp;};

    //Pure Virtual Methods
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(string, int, int) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual int PurchaseArmors(int) = 0;
};
#endif