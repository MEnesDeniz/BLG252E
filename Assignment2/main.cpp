#include "Person.h"
#include "Mission.h"
#include "Agency.h"

#include <iostream>
#include <cstdlib>


using namespace std;

// Initialize the static member
int Mission::numMissions = 0;

int main(int argc, char const *argv[])
{
    // Set the PRNG seed
    srand(1773);

    Agency newAgency = Agency("NASA",20000,-40);

    newAgency.setTicketPrice(10000);
    // Create astronauts
    Astronaut* astronautList[5];
    astronautList[0] = new Astronaut("Neil","Armstrong",1);
    astronautList[1] = new Astronaut("Buzz","Aldrin",-5);
    astronautList[2] = new Astronaut("Sally","Ride",0);
    astronautList[3] = new Astronaut("Judith","Resnik",4);
    astronautList[4] = new Astronaut("Yuri","Gagarin",5);


    // Create astronauts
    Passenger* passengerList[5];
    passengerList[0] = new Passenger("Dennis","Tito",12000);
    passengerList[1] = new Passenger("Mark","Shuttleworth",10000);
    passengerList[2] = new Passenger("Gregory","Olsen",15000);
    passengerList[3] = new Passenger("Charles","Simonyi",24000);
    passengerList[4] = new Passenger("Alperen","KantarcÄ±");

    // Every passenger tries to buy a ticket
    for(int i=0; i<5; i++){
        passengerList[i]->buyTicket(newAgency.getTicketPrice());
    }


    // Create moon mission
    Mission moonMission = Mission("MN-01",5000,20);
    
    moonMission += astronautList[0];
    moonMission += passengerList[0];
    newAgency.addMission(moonMission);

    // Create venus mission
    Mission venusMission = Mission("V",35000,99);

    cout << "Name of the mission: " << venusMission.getName() << endl;
    venusMission.setName("VS-01");
    
    venusMission += astronautList[1];
    venusMission += passengerList[1];
    
    newAgency.addMission(venusMission);

    Mission jupiter = Mission("TT-233",35000,99);

    cout << "Name of the mission: " << jupiter.getName() << endl;
    jupiter.setName("TT-23");
    
    jupiter += astronautList[2];
    jupiter += passengerList[2];
    
    newAgency.addMission(jupiter);

    Mission uranus = Mission("HJKE",35000,5);

    cout << "Name of the mission: " << uranus.getName() << endl;
    uranus.setName("UR-22");
    
    uranus += astronautList[3];
    uranus += passengerList[3];
    
    newAgency.addMission(uranus);

    Mission mars = Mission("V",35000,99);

    cout << "Name of the mission: " << mars.getName() << endl;
    mars.setName("VS-01");
    
    mars += astronautList[4];
    mars += passengerList[4];
    
    newAgency.addMission(mars);

    cout << newAgency;

    // Execute next mission
    newAgency.executeNextMission();

    cout << newAgency;

    // Execute another mission
    newAgency.executeNextMission();

    cout << newAgency << endl;
    
    newAgency.executeNextMission();
    newAgency.executeNextMission();
    newAgency.executeNextMission();
    cout << newAgency << endl;
    newAgency.executeNextMission();
    newAgency.executeNextMission();

    // Delete the allocated space
    for(int i=0; i<5; i++){
        delete astronautList[i];
        delete passengerList[i];
    }

    return 0;
}
