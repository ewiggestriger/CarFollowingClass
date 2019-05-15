//
// Created by John Kostoff on 2019-03-10.
//

#include <iostream>
#include <vector>
#include "Road.h"
#include "Car.h"

using namespace std;

//typedef Car *CarPtr; // assigns a pointer to a class
//Car *cars;  // declares a car point
int numCars;
vector<Car> cars;

Road::Road(int n)
{
    numCars = n;
    //Car carArray[n];
    //cars = carArray; // creates an array of car objects
    for (int i = 0; i < numCars; ++i)
    {
        cars.push_back(Car());
        cars[i].positionCS = -(double)i*4.0;  // initial position, velocity, time gap, sensitivity

    }
    for (int i = 1; i < numCars; ++i)
    {
        cars[i].setLeader(&cars[i], &cars[i-1]); // sets the order of the cars
    }
}


void Road::UpdateRoad(double deltaT)
{
    for (int i = 0; i < numCars ; ++i)
    {
        cars[i].ComputeNS(&cars[i], deltaT); // computes each car's next state
    }
    for (int j = 0; j < numCars; ++j)
    {
        cars[j].UpdateCS(&cars[j]); // updates the car's current state to the next state
    }
}

void Road::PrintRoad()
{
    for (int i = 0; i < numCars; ++i)
    {
        cout << cars[i].GetPosition(&cars[i]) << ", "; // prints out each car's position to the console
    }
    cout << endl;
}
