/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

//Person Class
class Person
{
private:
    string name;    //Person name
    string surname; //Person surname

public:
    Person(string = "", string = ""); //Constructor with argument also have default values so it covers also default constructor

    //Getters for People
    string getName() const { return this->name; };
    string getSurname() const { return this->surname; };

    //Setters for People
    void setName(string name) { this->name = name; };
    void setSurname(string surname) { this->surname = surname; };
};

//Passenger Class
class Passenger : public Person //Publicly inherit the Person class
{
private:
    int cash;        // Passenger's cash value
    bool ticket;     // Situation of passenger's ticket existence
    Passenger *next; //Passenger node

public:
    Passenger(string = "", string = "", int = 0); //Constructor with argument also have default values so it covers also default constructor
    bool buyTicket(int ticketPrice);              //Passenger is able to buy ticket with it's cash

    //Getters for Passenger
    int getCash() const { return this->cash; };
    Passenger *getNext() const { return this->next; };
    bool getTicket() const { return this->ticket; };

    //Setters for Passenger
    void setTicket(bool ticket) { this->ticket = ticket; };
    void setNext(Passenger *next) { this->next = next; };
    void setCash(int cash)
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
    };
};

//Astronaut Class
class Astronaut : public Person //Publicly inherit the Person class
{
private:
    int numMissions; //Astronout's executed mission number
    Astronaut *next; //Astronout node

public:
    Astronaut(string = "", string = "", int = 0); //Constructor with argument also have default values so it covers also default constructor
    void completeMission();                       //Astronout's executed mission number will increased

    //Getters for Astronaut
    Astronaut *getNext() const { return this->next; };
    int getnumMissions() const { return this->numMissions; };

    //Setters for Astronaut
    void setNext(Astronaut *next) { this->next = next; };
    void setnumMissions(int numMissions) { this->numMissions = numMissions; };
};
#endif
