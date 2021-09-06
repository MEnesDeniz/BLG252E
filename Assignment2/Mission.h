/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef MISSION_H
#define MISSION_H
#include <iostream>
#include <string>
#include <ctype.h>
#include "Person.h"
using namespace std;

class Mission
{
private:
    string name;            //Mission Name
    int missionNumber;      //Mission's own number e.g. Mission 1
    int cost;               //Mission cost
    int faultProbability;   //Missions's fault rate
    bool completed;         //Missions's completion status
    static int numMissions; //Static defined number of all missions will be invoked in the main and incremented in the each mission object creation
    Passenger *phead;       //Passenger list head
    Astronaut *chead;       //Crew list head
    Mission *next;          //Mission node

public:
    Mission(string = " ", int = 0, int = 0); //Constructor with argument also have default values so it covers also default constructor
    Mission(const Mission &);                //Copy constructor
    ~Mission();                              //Destructor
    void operator+=(Passenger *);            //Overloaded operator+ for missions in order to add passengers
    void operator+=(Astronaut *);            //Overloaded operator+ for missions in order to add crew member
    bool executeMission();                   //Execution of the mission and determining it's completion situation
    int calculateProfit(int);                //Calculate the profit of each succesfull mission

    //Setters for Mission
    void setName(string name)
    {
        if (name.length() == 5 && (isupper(name[0]) && isupper(name[1]) && name[2] == '-' && isdigit(name[3]) && isdigit(name[4])))
        {
            this->name = name;
        }
        else
        {
            cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        }
    };
    void setCompleted(bool status) { this->completed = status; };
    void setNext(Mission *next) { this->next = next; };
    void setCost(int cost) { this->cost = cost; };
    void setfaultRate(int faultRate) { this->faultProbability = faultRate; };

    //Getters for Mission
    int getmissionNumber() { return this->missionNumber; };
    int getCost() { return this->cost; };
    int getfaultRate() { return this->faultProbability; };
    Mission *getNext() { return this->next; };
    string getName() { return this->name; };
    Astronaut *getCrew() { return this->chead; };
    Passenger *getPassengers() { return this->phead; };
};
#endif