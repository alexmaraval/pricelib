//
//  random_generator.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 22.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "random_generator.hpp"

// --------------- Useful functions ------------------
double N(double x, double mean, double variance)
{
    return (mean + variance * 0.5 * erfc(-x * M_SQRT1_2));
}

double n(double x, double mean, double variance)
{
    return exp(-0.5 * (x - mean)*(x - mean) / variance) / (variance * sqrt(2*M_PI));
}


// --------------- Random Generator ------------------
Uniform::Uniform(double a, double b)
{
    _X = a + b * (1. + rand()) / (2. + (double) RAND_MAX);
}

double Uniform::get_x()
{
    return _X;
}

Normal::Normal(double mu, double sigma, string method)
{
    if (method == "bm")
    {
        double u1,u2,Z;
        u1 = (1. + rand()) / (2. + (double) RAND_MAX);
        u2 = (1. + rand()) / (2. + (double) RAND_MAX);
        Z = sqrt(-2*log(u1))*sin(2*M_PI*u2);
        _X = mu + sigma*Z;
    }
    else if (method == "m")
    {
        double u1,u2,v1,v2,W,Z;
        do {
            u1 = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
            u2 = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
            v1 = 2*u1-1;
            v2 = 2*u2-1;
            W = v1*v1 + v2*v2;
        } while (W > 1 || W == 0);
        Z = sqrt(-2*log(W)/W)*v1;
        _X = mu + sigma*Z;
    }
}

double Normal::get_x()
{
    return _X;
}
