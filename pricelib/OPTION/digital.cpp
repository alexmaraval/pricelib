//
//  digital.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 05.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "digital.hpp"

Digital::Digital()
{
    _T = _S = _sigma = _r = _q = Parameter();
    _model = "bs";
    _payoff = Payoff();
}

Digital::Digital(const Parameter& T, const Parameter& S, const Parameter& sigma, const Parameter& r, const Parameter& q, const Payoff& p, string model)
: European(T, S, sigma, r, q, p, model)
{
    _price = price(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _delta = delta(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _gamma = gamma(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _theta = theta(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _vega = vega(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _rho = rho(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _lambda = lambda(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _vanna = vanna(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _charm = charm(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _speed = speed(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _color = color(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _volga = volga(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _veta = veta(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
    _zomma = zomma(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value(), _model, p.get_flag());
}


// ---------------------------- Price and Greeks Computation ----------------------------
double Digital::price(double K, double T, double S, double sigma, double r, double q, string model, bool type)
{
    double Call = S * exp(-q * T) * N(d1(K, T, S, sigma, r, q));
    double Put =  S * exp(-q * T) * N(-d1(K, T, S, sigma, r, q));
    return (1-type) * Call + type * Put;
}

double Digital::auto_price() const
{
    return _price;
}



double Digital::delta(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::gamma(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::theta(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::vega(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::rho(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::lambda(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::vanna(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::charm(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::speed(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::color(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::volga(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::veta(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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

double Digital::zomma(double K, double T, double S, double sigma, double r, double q, string model, bool type)
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
void Digital::print() const
{
    string cp = {};
    if(_payoff.get_flag() == 0){cout << "------- Digital Call -------" << endl;}
    else {cout << "------- Digital Put --------" << endl;}
    cout << "Strike                " << _payoff.get_strike() << endl;
    cout << "Maturity              " << _T.get_value() << endl;
    cout << "Spot                  " << _S.get_value() << endl;
    cout << "Implied Volatility    " << _sigma.get_value() << endl;
    cout << "Interest Rate         " << _r.get_value() << endl;
    cout << "Dividend Rate         " << _q.get_value() << endl;
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

