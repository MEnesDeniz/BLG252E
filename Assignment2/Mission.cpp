/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Person.h"
#include <string>
#include <ctype.h>
#include "Mission.h"

using namespace std;

Mission::Mission(string name, int cost, int faultProbability)
{
    this->numMissions++;
    this->missionNumber = this->numMissions;
    this->completed = false;
    this->next = NULL;
    this->phead = NULL;
    this->chead = NULL;
    this->cost = cost;
    this->faultProbability = faultProbability;

    if (name.length() == 5 && (isupper(name[0]) && isupper(name[1]) && name[2] == '-' && isdigit(name[3]) && isdigit(name[4])))
    {
        this->name = name;
    }
    else
    {
        this->name = "AA-00";
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
    }
}

Mission::~Mission()
{
    Astronaut *todel = this->chead;
    while (chead != NULL) //Destroy the crew linked list
    {
        this->chead = todel->getNext();
        delete todel;
        todel = chead;
    }

    Passenger *delthis = this->phead;
    while (phead != NULL) //Destroy the passenger linked list
    {
        this->phead = delthis->getNext();
        delete delthis;
        delthis = phead;
    }
}
Mission::Mission(const Mission &objectIn)
{
    this->name = objectIn.name;
    this->missionNumber = objectIn.missionNumber;
    this->numMissions = objectIn.numMissions;
    this->cost = objectIn.cost;
    this->faultProbability = objectIn.faultProbability;
    this->completed = objectIn.completed;
    this->next = NULL;

    //Creating new Astronaut list for newly constructed object from the incoming object.
    //  Creating new dynamically allocated crew member in each step.
    //       Could also be used operator= in here but I feel more confident with the old style
    this->chead = new Astronaut(*objectIn.chead);
    Astronaut *copyPtr = objectIn.chead->getNext();
    Astronaut *thisPtr = this->chead;
    while (copyPtr != NULL)
    {
        thisPtr->setNext(new Astronaut(copyPtr->getName(), copyPtr->getSurname(), copyPtr->getnumMissions()));
        copyPtr = copyPtr->getNext();
        thisPtr = thisPtr->getNext();
    }

    //Creating new Passenger list for newly constructed object from the incoming object.
    //  Creating new dynamically allocated passenger member in each step.
    //      Could also be used operator= in here but I feel more confident with the old style
    this->phead = new Passenger(*objectIn.phead);
    Passenger *pcopyPtr = objectIn.phead->getNext();
    Passenger *pthisPtr = this->phead;
    while (pcopyPtr != NULL)
    {
        pthisPtr->setNext(new Passenger(pcopyPtr->getName(), pcopyPtr->getSurname(), pcopyPtr->getTicket()));
        pcopyPtr = pcopyPtr->getNext();
        pthisPtr = pthisPtr->getNext();
    }
}

void Mission::operator+=(Passenger *newPassenger)
{
    if (newPassenger->getTicket())
    {
        if (this->phead == NULL)
        {
            this->phead = new Passenger(newPassenger->getName(), newPassenger->getSurname(), newPassenger->getTicket());
        }
        // if Mission has existing passengers, add new passgenger at the end of the linked list
        else
        {
            Passenger *ptr = this->phead;

            while (ptr->getNext() != NULL)
            {
                ptr = ptr->getNext();
            }
            ptr->setNext(new Passenger(newPassenger->getName(), newPassenger->getSurname(), newPassenger->getTicket()));
        }
    }
    else
    {
        cerr << "Passenger " << newPassenger->getName() << " " << newPassenger->getSurname() << " does not have a valid ticket!";

    }
}

void Mission::operator+=(Astronaut *newAstronaut)
{
    if (this->chead == NULL)
    {
        this->chead = new Astronaut(newAstronaut->getName(), newAstronaut->getSurname(), newAstronaut->getnumMissions());
        chead->setNext(NULL);
    }
    // if Mission has existing astronouts, add new astronout at the end of the linked list
    else
    {
        Astronaut *ptr = this->chead;

        while (ptr->getNext() != NULL)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(new Astronaut(newAstronaut->getName(), newAstronaut->getSurname(), newAstronaut->getnumMissions()));
    }
}

bool Mission::executeMission()
{
    int successrate = rand() % 100; //Mission successrate will be between 0-99 both of them included
    int faultrate = getfaultRate();
    if (successrate > faultrate)
    {
        cout << "MISSION " << getName() << " SUCCESSFUL!" << endl;
        Astronaut *traverse = chead;
        while (traverse != NULL)
        {
            traverse->completeMission();
            cout << "Astronaut " << traverse->getName() << " " << traverse->getSurname() << " "
                 << "successfully completed " << traverse->getnumMissions() << " "
                 << "missions." << endl;
            traverse = traverse->getNext();
        }
        setCompleted(true);
        return true;
    }
    else
    {
        cout << "MISSION " << getName() << " FAILED!" << endl;
        cout << "Agency reschedules the mission." << endl;
        setCompleted(false);
        return false;
    }
}

int Mission::calculateProfit(int ticketPrice)
{
    if (completed == true)
    {
        int numofPassenger = 0;
        Passenger *traverse = phead;
        while (traverse != NULL)
        {
            numofPassenger++;
            traverse = traverse->getNext();
        }
        int revenue = ticketPrice * numofPassenger;
        return revenue - cost;
    }
    else
    {
        return -cost;
    }
}
