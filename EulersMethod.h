//
// Created by John Kostoff on 2019-03-10.
//

#pragma once


class EulersMethod {
public:
    EulersMethod();

    ~EulersMethod();

    double Euler(double x, double dxdt, double deltaT);
};
