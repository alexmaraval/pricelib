//
//  digital.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 05.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef digital_hpp
#define digital_hpp

#include "european.hpp"
using namespace std;

class Digital : public European
{
private:
    
protected:
    
public:
    
    // Constructor
    Digital();
    Digital(const Parameter& T, const Parameter& S, const Parameter& sigma, const Parameter& r, const Parameter& q, const Payoff& p, string model);
    // Copy Constructor
    // Destructor
    
    virtual double price(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double auto_price() const;
    
    virtual double delta    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double gamma    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double vega     (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double theta    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double rho      (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double lambda   (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double vanna    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double charm    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double speed    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double color    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double volga    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double veta     (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    virtual double zomma    (double K, double T, double S, double sigma, double r, double q, string model, bool cpflag);
    
    // Print function
    virtual void print() const;
};


#endif /* digital_hpp */
