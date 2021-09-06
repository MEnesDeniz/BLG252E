/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Person.h"
using namespace std;

//Person Class Methods//

Person::Person(string name, string surname)
{
    this->name = name;
    this->surname = surname;
}

//Passenger Class Methods//

Passenger::Passenger(string name, string surname, int cash) : Person(name, surname)
{
    if (cash < 0)
    {
        cerr << "Passenger cash can’t be negative. It is set to 0." << endl;
        this->cash = 0;
    }
    else
    {
        this->cash = cash;
    }
    this->ticket = false;
    this->next = NULL;
}

bool Passenger::buyTicket(int ticketPrice)
{
    if (cash >= ticketPrice) //If the passenger have enough cash value
    {
        int remainingCash = cash - ticketPrice;
        setTicket(true);        //Passenger is able to buy the ticket
        setCash(remainingCash); //Passenger's new cash which is cash - ticketPrice
        return true;
    }
    else //If the passenger have not enough cash value
    {
        setTicket(false); //Passenger could'nt buy the ticket
        return false;
    }
}

//Astronaut Class Methods//

Astronaut::Astronaut(string name, string surname, int missions) : Person(name, surname)
{
    this->next = NULL;
    if (missions < 0) //If the number of the completed mission's set as negative it will raise error
    {
        numMissions = 0;
        cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
    }
    else
    {
        numMissions = missions;
    }
}

void Astronaut::completeMission() //Increase the number of executed missions for astronout
{
    numMissions++;
}