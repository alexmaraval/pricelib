//
//  random_generator.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 22.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef random_generator_hpp
#define random_generator_hpp

#include <stdio.h>
#include "option.hpp"
using namespace std;

// --------------- Useful functions ------------------
double N(double x, double mean = 0, double variance = 1);
double n(double x, double mean = 0, double variance = 1);


// --------------- Random Generator ------------------
class Randgen
{
private:
    
protected:
    double _X;
    
public:
    virtual double get_x() = 0;
};

class Uniform : public Randgen
{
private:
    double _a, _b;
    
public:
    Uniform(double a = 0, double b = 1);
    double get_x();
};

class Normal : public Randgen
{
private:
    double _mu, _sigma;
    string _method;
public:
    Normal(double mu = 0, double sigma = 1, string method = "bm");
    double get_x();
};
#endif /* random_generator_hpp */
