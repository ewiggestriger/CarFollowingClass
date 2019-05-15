//
// Created by John Kostoff on 2019-03-10.
//

#include "EulersMethod.h"

EulersMethod::EulersMethod() = default;

EulersMethod::~EulersMethod() = default;

double EulersMethod::Euler(double x, double dxdt, double deltaT)
{
    return (x + deltaT*dxdt);
}