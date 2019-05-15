//
// Created by John Kostoff on 2019-03-10.
//

#pragma once


class Car
{
private:
    double positionCS; // current position
    double positionNS; // next position
    double velocityCS; // current velocity
    double velocityNS; // next velocity
    double accelerationCS; // current acceleration
    double accelerationNS; // next acceleration
    double timeGap;
    double sensitivity;
    Car *leader; // pointer to leader
    friend class Road; // so Road can access private members of Car

public:
    Car(); // generic constructor
    ~Car();
    double ControllerAcceleration(Car *car);
    void setLeader(Car*,Car*);
    void ComputeNS(Car *car, double deltaT);
    void UpdateCS(Car *car);
    double GetPosition(Car *car);
};



