//
//  european.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 24.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef european_hpp
#define european_hpp

#include <stdio.h>
#include "option.hpp"
using namespace std;

class European : public Option
{
private:
    double _d1, _d2;
    
protected:
    Parameter _T;                                          // Time to Maturity
    Parameter _S;                                          // Spot price of the Underlying
    Parameter _sigma;                                      // Volatility
    Parameter _r;                                          // Interest Rate
    Parameter _q;                                          // Compounded Dividend Rate
    
    double _delta;
    double _gamma;
    double _theta;
    double _vega;
    double _rho;
    double _lambda;
    double _vanna;
    double _charm;
    double _speed;
    double _color;
    double _volga;
    double _veta;
    double _zomma;
    
    string _model;                                      // Pricing Model: bs, heston or crr
    
public:
    
    // Constructor
    European();
    European(const Parameter& T, const Parameter& S, const Parameter& sigma, const Parameter& r, const Parameter& q, const Payoff& p, string model);
    // Copy Constructor
    // Destructor

    
    // Payoff, Price and Greeks functions
    
    virtual double d1(double K, double T, double S, double sigma, double r, double q);
    virtual double d2(double K, double T, double S, double sigma, double r, double q);
    
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
    
    // Accessors
    virtual double get_strike() const;
    virtual double get_maturity() const;
    virtual double get_spot() const;
    virtual double get_vol() const;
    virtual double get_interest() const;
    virtual double get_div() const;
    virtual double get_price() const;
    virtual double get_delta() const;
    virtual double get_gamma() const;
    virtual double get_vega() const;
    virtual double get_theta() const;
    virtual double get_rho() const;
    virtual double get_lambda() const;
    virtual double get_vanna() const;
    virtual double get_charm() const;
    virtual double get_speed() const;
    virtual double get_color() const;
    virtual double get_volga() const;
    virtual double get_veta() const;
    virtual double get_zomma() const;
    
    void set_strike(const Parameter& K);
    void set_maturity(const Parameter& T);
    
};


#endif /* european_hpp */
