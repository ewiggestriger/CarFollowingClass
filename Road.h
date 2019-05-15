//
// Created by John Kostoff on 2019-03-10.
//

#pragma once
#include "Car.h"


class Road
{

public:
    explicit Road(int n);
    void UpdateRoad(double deltaT);
    void PrintRoad();
};

