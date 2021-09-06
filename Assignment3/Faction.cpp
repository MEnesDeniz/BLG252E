/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Faction.h"
using namespace std;

Faction::Faction(string name, int units, int ap, int hp, int regen)//Constructor
{
    this->name = name;
    this->number_of_units = units;
    this->attack_points = ap;
    this->health_points = hp;
    this->regen_num = regen;
    this->first_enemy = NULL;
    this->second_enemy = NULL;

    this->total_health = (this->number_of_units * this->health_points);
    if (total_health > 0)
    {
        this->is_alive = true;
    }
    else
    {
        this->is_alive = false;
    }
}

void Faction::AssignEnemies(Faction *f1, Faction *f2)
{
    this->first_enemy = f1;
    this->second_enemy = f2;
}

void Faction::Print()
{
    string status_info;
    bool flag = IsAlive();
    if (flag == true)
    {
        status_info = "Alive";
    }
    else
    {
        status_info = "Defeated";
    }

    cout << "Faction Name:         " << this->name << endl;
    cout << "Status:               " << status_info << endl; //Burayı düzeltmen gerekebilir
    cout << "Number of Units:      " << this->number_of_units << endl;
    cout << "Attack Point:         " << this->attack_points << endl;
    cout << "Health Point:         " << this->health_points << endl;
    cout << "Unit Regen Number:    " << this->regen_num << endl;
    cout << "Total Faction Health: " << this->total_health << endl;
}

void Faction::EndTurn()
{
    if (number_of_units <= 0)//If the number of units is less than 0 at the end of the turn, method should set it to 0.
    {
        number_of_units = 0;//If no man left then it lose
        setAlive(false);//Set it's alive status as defeated
    }
    else
    {
        number_of_units += regen_num;//If it still survives then it's army will heal up
    }
    total_health = number_of_units * health_points;//Update the total_health
}