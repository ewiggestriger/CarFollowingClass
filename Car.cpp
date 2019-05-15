//
// Created by John Kostoff on 2019-03-10.
//
#include <iostream>
#include "Car.h"
#include "EulersMethod.h"

using namespace std;

Car::Car()
{
    positionCS = 0.0;
    positionNS = 0.0;
    velocityCS = 0.0;
    velocityNS = 0.0;
    accelerationCS = 0;
    accelerationNS = 0.0;
    leader = 0;
    timeGap = 2.0;
    sensitivity = 0.7;
}

Car::~Car() = default;

double Car::ControllerAcceleration(Car *car)
{
    return (car->sensitivity * ((car->leader->positionCS - car->positionCS) - car->velocityCS * car->timeGap));
}

void Car::setLeader(Car *car, Car *leader)
{
    car->leader = leader;
    car->accelerationCS = ControllerAcceleration(car);
}

double MPH2FPS (double mph)
{
    return (mph * 5280 / 3600);
}

void Car::ComputeNS(Car *car, double deltaT)
{
    static int leaderState = 0;
    static double leaderTimer = 0.0;

    EulersMethod E; // create EulersMethod object to use its functions

    if (car->leader == 0) // car is the leader
    {
        switch (leaderState)
        {
            case 0:
                if (car->velocityCS < MPH2FPS(60.0))
                {
                    car->accelerationNS = 8.82; // leader accelerates to 60 mph
                }
                else
                {
                    car->accelerationNS = 0.0;
                    leaderState = 1;
                    leaderTimer = 0.0;
                }
                break;
            case 1:
                if (leaderTimer < 10.0)
                {
                    car->accelerationNS = 0.0; // leader stays at 60 mph for 10 seconds
                }
                else
                {
                    car->accelerationNS = -8.82;
                    leaderState = 2;
                }
                leaderTimer += deltaT;
                break;
            case 2:
                if (car->velocityCS > 0)
                {
                    car->accelerationNS = -8.82; // leader decelerates to 0 mph after 10 seconds
                }
                else
                {
                    car->accelerationNS = 0.0;
                    leaderState = 3;
                }
                break;
            case 3:
                car->accelerationNS = 0.0; // leader stays at 0 mph
                break;
            default:
                break;
        }
        car->velocityNS = car->velocityCS + car->accelerationCS * deltaT; // computes next state velocity
        car->positionNS = car->positionCS + car->velocityCS * deltaT; // computes next state position
    }
    else
    {
        double distance = GetPosition(car->leader) - car->positionCS;
        car->accelerationNS = ControllerAcceleration(car);
        car->velocityNS = E.Euler(car->velocityCS,car->accelerationCS,deltaT);
        car->positionNS = E.Euler(car->positionCS,car->velocityCS,deltaT);
    }
}

void Car::UpdateCS(Car *car)
{
    car->accelerationCS = car->accelerationNS;
    car->velocityCS = car->velocityNS;
    car->positionCS = car->positionNS;
}

double Car::GetPosition(Car *car)
{
    return car->positionCS;
}