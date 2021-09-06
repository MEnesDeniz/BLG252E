/**
 * @author Muhammed Enes Deniz / 070170450
 * denizm17.edu.tr
 */

#include "Person.h"
#include "Mission.h"
#include "Agency.h"
#include <string>
#include <iostream>

using namespace std;

Agency::Agency(string name, int cash, int ticketPrice)
{
    this->name = name;
    this->cash = cash;
    if (ticketPrice < 0)
    {
        cerr << "Ticket price can't be negative. It is set to 0." << endl;
        this->ticketPrice = 0;
    }
    else
    {
        this->ticketPrice = ticketPrice;
    }
    this->completedMissions = NULL;
    this->nextMissions = NULL;
}

Agency::~Agency()
{
    Mission *todel = nextMissions;
    while (nextMissions != NULL)
    {
        nextMissions = todel->getNext();
        delete todel;
        todel = nextMissions;
    }

    todel = completedMissions;
    while (completedMissions != NULL)
    {
        completedMissions = todel->getNext();
        delete todel;
        todel = completedMissions;
    }
}

void Agency::addMission(Mission &newMission)
{
    Mission *toadd = new Mission(newMission); // call the copy constructor

    if (this->nextMissions == NULL) // if the head is empty add to the head
    {
        this->nextMissions = toadd;
    }
    else
    {
        Mission *ptr = nextMissions;
        while (ptr->getNext() != NULL) // add to the end of the list
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(toadd);
    }
}

void Agency::executeNextMission()
{
    if (nextMissions != NULL)
    {
        if (nextMissions->executeMission() == true) //succesfully completed mission
        {
            Mission *completedOne = nextMissions;                                //the mission that is in the head of the next mission array will be completed one
            nextMissions = nextMissions->getNext();                              // new head will be the head's next head = head->next
            completedOne->setNext(NULL);                                         //the completed one(old head) will be ripped away from the list
            int profit = getCash() + completedOne->calculateProfit(ticketPrice); // calculate the profit of the completed mission
            setCash(profit);                                                     // set the profit
            if (this->completedMissions == NULL)
            {
                this->completedMissions = completedOne; // if the head of the completedMissions is empty add to the head of the list
            }
            else
            {
                completedOne->setNext(completedMissions); // set the newest mission as the head of the completedMissions
                completedMissions = completedOne;
            }
        }
        else //failed mission
        {
            Mission *notcompletedOne = nextMissions;                                //taking the head mission (failed mission)
            nextMissions = nextMissions->getNext();                                 // head = head->next
            notcompletedOne->setNext(NULL);                                         // seperate the failed mission
            int profit = getCash() + notcompletedOne->calculateProfit(ticketPrice); // calculate the lost
            setCash(profit);
            Mission *ptr = nextMissions;
            if (ptr == NULL)
            {
                nextMissions = notcompletedOne;
            }
            else
            {
                while (ptr->getNext() != NULL)
                {
                    ptr = ptr->getNext();
                }
                ptr->setNext(notcompletedOne);
            }
        }
    }
    else
    {
        cout << "No available mission to execute!" << endl;
    }
}

ostream &operator<<(ostream &stream, const Agency &agency)
{
    stream << "Agency name: " << agency.getName() << ", "
           << "Total cash: " << agency.getCash() << ", "
           << "Ticket Price: " << agency.getTicketPrice() << endl;
    stream << "Next Missions:" << endl;
    Mission *ptr = agency.getNextMissions();
    if (ptr == NULL)
    {
        stream << "No missions available." << endl;
    }
    while (ptr != NULL)
    {
        stream << "Mission number: " << ptr->getmissionNumber() << " "
               << "Mission name: " << ptr->getName() << " "
               << "Cost: " << ptr->getCost() << endl;
        ptr = ptr->getNext();
    }

    stream << "Completed Missions:" << endl;
    ptr = agency.getcompletedMissions();
    if (ptr == NULL)
    {
        stream << "No missions completed before." << endl;
    }
    while (ptr != NULL)
    {
        stream << "Mission number: " << ptr->getmissionNumber() << " "
               << "Mission name: " << ptr->getName() << " "
               << "Cost: " << ptr->getCost() << endl;
        ptr = ptr->getNext();
    }
    return stream;
}