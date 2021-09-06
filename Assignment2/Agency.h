/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef AGENCY_H
#define AGENCY_H
#include <iostream>
#include <string>
#include "Mission.h"
using namespace std;

class Agency
{
private:
    string name;                //Agency name
    int cash;                   //Agency's current cash
    int ticketPrice;            //Agency's ticket price
    Mission *completedMissions; //Agency's completed mission list head
    Mission *nextMissions;      //Agency's next mission list head

public:
    Agency(string = "", int = 0, int = 0);                 //Constructor with argument also have default values so it covers also default constructor
    ~Agency();                                             //Destructor for Agency
    void addMission(Mission &);                            //Adding mission to the next mission list
    void executeNextMission();                             //Executing from the tail of the next mission and if it's succesfull add the executed mission to the completed mission list
    friend ostream &operator<<(ostream &, const Agency &); //Overloaded operator<< for agency decleared as a friend function I have decleared as a friend because I want to call this one from the object level.
                                                           //So by declearing as friend I will ensure it will access my all attribitues. Also I check various resources it all emphasis that operator<< should be
                                                           //overloaded as a friend function.

    //Setters
    void setCash(int cash) { this->cash = cash; };
    void setTicketPrice(int price) { this->ticketPrice = price; };
    void setName(string name) { this->name = name; };

    //Getters
    string getName() const { return this->name; };
    int getCash() const { return this->cash; };
    Mission *getNextMissions() const { return this->nextMissions; };
    int getTicketPrice() const { return this->ticketPrice; };
    Mission *getcompletedMissions() const { return this->completedMissions; };
};
#endif