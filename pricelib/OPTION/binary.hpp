//
//  binary.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 24.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef binary_hpp
#define binary_hpp

#include <stdio.h>
#include "european.hpp"
using namespace std;

class Binary : public European
{
private:
    
protected:
    
public:
    
    // Constructor
    Binary(double K = 0, double T = 0, double S = 0, double sigma = 1, double r = 0, double d = 0, bool cpflag = 0, string model = "bs");
    // Copy Constructor
    // Destructor
    
    
    virtual double payoff(double x);
    
    virtual double price(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double auto_price();
    
    virtual double delta(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double gamma(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double vega(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double theta(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double rho(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double lambda(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double vanna(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double charm(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double speed(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double color(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double volga(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double veta(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    virtual double zomma(double K, double T, double S, double sigma, double r, double q, bool type, string model);
    
    // Print function
    virtual void print();
};

#endif /* binary_hpp */
