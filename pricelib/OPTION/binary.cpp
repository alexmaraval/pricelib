//
//  binary.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 24.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "binary.hpp"

Binary::Binary(double K, double T, double S, double sigma, double r, double q, bool cpflag, string model)
: European(K, T, S, sigma, r, q, cpflag, model)
{
    _price = price(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _delta = delta(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _gamma = gamma(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _theta = theta(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _vega = vega(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _rho = rho(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _lambda = lambda(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _vanna = vanna(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _charm = charm(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _speed = speed(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _color = color(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _volga = volga(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _veta = veta(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
    _zomma = zomma(_K, _T, _S, _sigma, _r, _q, _cpflag, _model);
}

// ---------------------------- Price and Greeks Computation ----------------------------
double Binary::payoff(double x)
{
    if(_cpflag == 0)
    {
        if(x>_K) {return 1;} else {return 0;}
    }
    else
    {
        if(x<_K) {return 1;} else {return 0;}
    }
}

double Binary::price(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    double Call = S * exp(-q * T) * N(d1(K, T, S, sigma, r, q));
    double Put =  S * exp(-q * T) * N(-d1(K, T, S, sigma, r, q));
    return (1-type) * Call + type * Put;
}

double Binary::auto_price()
{
    return _price;
}



double Binary::delta(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        double delta_call = exp(-q * T) * N( d1(K, T, S, sigma, r, q) + n( d1(K, T, S, sigma, r, q)) / (sigma * sqrt(T)));
        double delta_put  = exp(-q * T) * N(-d1(K, T, S, sigma, r, q) - n(-d1(K, T, S, sigma, r, q)) / (sigma * sqrt(T)));
        return (1-type) * delta_call + type * delta_put;
    }
}

double Binary::gamma(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    double gamma_call = exp(-q * T) * n( d1(K, T, S, sigma, r, q)) * (1 - d1(K, T, S, sigma, r, q) / (sigma * sqrt(T))) / (S * sigma * sqrt(T));
    double gamma_put  = exp(-q * T) * n(-d1(K, T, S, sigma, r, q)) * (d1(K, T, S, sigma, r, q) / (sigma * sqrt(T)) - 1) / (S * sigma * sqrt(T));
    return (1 - type) * gamma_call + type * gamma_put;
}

double Binary::theta(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    double theta_call = exp(-q * T) * S * n(d1(K, T, S, sigma, r, q)) * ((r - q - 0.5 * sigma * sigma) / (sigma * sqrt(T)) - 0.5 * d1(K, T, S, sigma, r, q) / T) - q * exp(-q * T) * S * N(d1(K, T, S, sigma, r, q));
    double theta_put  = exp(-q * T) * S * n(d1(K, T, S, sigma, r, q)) * (0.5 * d1(K, T, S, sigma, r, q) / T - (r - q - 0.5 * sigma * sigma) / (sigma * sqrt(T))) - q * exp(-q * T) * S * N(d1(K, T, S, sigma, r, q));
    return (1 - type) * theta_call + type * theta_put;
}

double Binary::vega(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    double vega_call = -exp(-q * T) * S * n( d1(K, T, S, sigma, r, q)) * d2(K, T, S, sigma, r, q) / sigma;
    double vega_put  =  exp(-q * T) * S * n(-d1(K, T, S, sigma, r, q)) * d2(K, T, S, sigma, r, q) / sigma;
    return (1 - type) * vega_call + type * vega_put;
}

double Binary::rho(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    double rho_call = exp(-q * T) * S * n( d1(K, T, S, sigma, r, q)) * sqrt(T) / sigma;
    double rho_put  = exp(-q * T) * S * n(-d1(K, T, S, sigma, r, q)) * sqrt(T) / sigma;
    return (1 - type) * rho_call + type * rho_put;
}

double Binary::lambda(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    double lambda_call = 1 + n( d1(K, T, S, sigma, r, q)) / (sigma * sqrt(T) * N( d1(K, T, S, sigma, r, q)));
    double lambda_put  = 1 - n(-d1(K, T, S, sigma, r, q)) / (sigma * sqrt(T) * N(-d1(K, T, S, sigma, r, q)));
    return (1 - type) * lambda_call + type * lambda_put;
}

double Binary::vanna(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::charm(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::speed(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::color(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::volga(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::veta(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}

double Binary::zomma(double K, double T, double S, double sigma, double r, double q, bool type, string model)
{
    if(model == "heston")
    {
        return 0;
    }
    else if(model == "crr")
    {
        return 0;
    }
    else
    {
        
    }
    return 0;
}


// ---------------------------- Print function ----------------------------
void Binary::print()
{
    string cp = {};
    if(_cpflag == 0){cout << "------- Binary Call -------" << endl;}
    else {cout << "------- Binary Put --------" << endl;}
    cout << "Strike                " << _K << endl;
    cout << "Maturity              " << _T << endl;
    cout << "Spot                  " << _S << endl;
    cout << "Implied Volatility    " << _sigma << endl;
    cout << "Interest Rate         " << _r << endl;
    cout << "Dividend Rate         " << _q << endl;
    cout << endl;
    cout << "--> BS Price : " << _price << endl;
    cout << endl;
    cout << "Delta                 " << _delta << endl;
    cout << "Gamma                 " << _gamma << endl;
    cout << "Theta                 " << _theta << endl;
    cout << "Vega                  " << _vega << endl;
    cout << "Rho                   " << _rho << endl;
    cout << "Lambda                " << _lambda << endl;
    cout << "Vanna                 " << _vanna << endl;
    cout << "Charm                 " << _charm << endl;
    cout << "Speed                 " << _speed << endl;
    cout << "Color                 " << _color << endl;
    cout << "Volga                 " << _volga << endl;
    cout << "Veta                  " << _veta << endl;
    cout << "Zomma                 " << _zomma << endl;
    cout << "------------------------------" <<  endl;
    cout << endl;
}

