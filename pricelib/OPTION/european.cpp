//
//  european.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 24.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "european.hpp"

// ---------------------------- Constructor
European::European()
{
    _T = _S = _sigma = _r = _q = Parameter();
    _model = "bs";
    _payoff = Payoff();
}


European::European(const Parameter& T, const Parameter& S, const Parameter& sigma, const Parameter& r, const Parameter& q, const Payoff& p, string model)
{
    _T = T;
    _S = S;
    _sigma = sigma;
    _r = r;
    _q = q;
    _model = model;
    
    _payoff = p;
    
    _d1 = d1(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value());
    _d2 = d2(p.get_strike(), _T.get_value(), _S.get_value(), _sigma.get_value(), _r.get_value(), _q.get_value());
    
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

// ---------------------------- Copy Constructor ----------------------------




// ---------------------------- Destructor ----------------------------



// --------------------------------------------------------------------------------------------
// ---------------------------- Payoff, Price and Greeks functions ----------------------------
// --------------------------------------------------------------------------------------------


// ---------------------------- d1 and d2 functions ----------------------------
double European::d1(double K, double T, double S, double sigma, double r, double q)
{
    return (log(S/K) + (r + - q + 0.5*sigma*sigma)*T)/(sigma*sqrt(T));
}

double European::d2(double K, double T, double S, double sigma, double r, double q)
{
    return d1(K, T, S, sigma, r, q) - sigma * sqrt(T);
}


// ---------------------------- Price Function ----------------------------
double European::price(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        double Call = S * exp(q * T) * N(d1(K, T, S, sigma, r, q)) - K * exp(-r * T) * N(d2(K, T, S, sigma, r, q));
        double Put =  K * exp(-r * T) * N(-d2(K, T, S, sigma, r, q)) - S * exp(q * T) * N(-d1(K, T, S, sigma, r, q));
        return (1-cpflag) * Call + cpflag * Put;
    }
}

double European::auto_price() const
{
    return _price;
}


// ---------------------------- Delta ----------------------------
double European::delta(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        double delta_call = exp(-q * T) * N(d1(K, T, S, sigma, r, q));
        double delta_put  = exp(-q * T) * (N(d1(K, T, S, sigma, r, q)) - 1);
        return (1-cpflag) * delta_call + cpflag * delta_put;
    }
}


// ---------------------------- Gamma ----------------------------
double European::gamma(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return exp(-q * T) * n(d1(K, T, S, sigma, r, q)) / (S * sigma * sqrt(T));
    }
}


// ---------------------------- Theta ----------------------------
double European::theta(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        double theta_call = S * exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * sigma / (2 * sqrt(T)) - q * S * exp(-q * T) * N(d1(K, T, S, sigma, r, q))  + r * K * exp(-r * T) * N(d2(K, T, S, sigma, r, q));
        double theta_put  = S * exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * sigma / (2 * sqrt(T)) + q * S * exp(-q * T) * N(-d1(K, T, S, sigma, r, q)) - r * K * exp(-r * T) * N(-d2(K, T, S, sigma, r, q));
        return -((1 - cpflag) * theta_call +cpflag * theta_put); // theta is usually a negative number
    }
}


// ---------------------------- Vega ----------------------------
double European::vega(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return S * exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * sqrt(T);
    }
}


// ---------------------------- Rho ----------------------------
double European::rho(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        double rho_call =  K * T * exp(-r * T) * N(d2(K, T, S, sigma, r, q));
        double rho_put  = -K * T * exp(-r * T) * N(-d2(K, T, S, sigma, r, q));
        return (1 - cpflag) * rho_call + cpflag * rho_put;
    }
}


// ---------------------------- Lambda ----------------------------
double European::lambda(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return delta(K, T, S, sigma, r, q, model, cpflag) * S / price(K, T, S, sigma, r, q, model, cpflag);
    }
}

double European::vanna(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return - exp(q * T) * n(d1(K, T, S, sigma, r, q)) * d2(K, T, S, sigma, r, q) / sigma;
    }
}

double European::charm(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        double charm_call =  q * exp(-q * T) * N(d1(K, T, S, sigma, r, q)) - exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * (2 * (r - q) * T - d2(K, T, S, sigma, r, q) * sigma * sqrt(T)) / (2 * sigma * T * sqrt(T));
        double charm_put  = -q * exp(-q * T) * N(d1(K, T, S, sigma, r, q)) - exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * (2 * (r - q) * T - d2(K, T, S, sigma, r, q) * sigma * sqrt(T)) / (2 * sigma * T * sqrt(T));
        return (1 - cpflag) * charm_call + cpflag * charm_put;
    }
}

double European::speed(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return -gamma(K, T, S, sigma, r, q, model, cpflag) / S * (1 + d1(K, T, S, sigma, r, q) / (sigma * sqrt(T)));
    }
}

double European::color(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return -exp(-q * T) * n(d1(K, T, S, sigma, r, q)) / (2 * sigma * T * sqrt(T)) * (2 * q * T + 1 + d1(K, T, S, sigma, r, q) * (2 * (r - q) * T - d2(K, T, S, sigma, r, q) * sigma * sqrt(T)) / (sigma * sqrt(T)));
    }
}

double European::volga(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return vega(K, T, S, sigma, r, q, model, cpflag) * d1(K, T, S, sigma, r, q) * d2(K, T, S, sigma, r, q) / sigma;
    }
}

double European::veta(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return S * exp(-q * T) * n(d1(K, T, S, sigma, r, q)) * sqrt(T) * (q + d1(K, T, S, sigma, r, q) * (r - q) / (sigma * sqrt(T)) - 0.5 * (1 + d1(K, T, S, sigma, r, q) * d1(K, T, S, sigma, r, q)) / T);
    }
}

double European::zomma(double K, double T, double S, double sigma, double r, double q, string model, bool cpflag)
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
        return gamma(K, T, S, sigma, r, q, model, cpflag) * (d1(K, T, S, sigma, r, q) * d2(K, T, S, sigma, r, q) - 1) / sigma;
    }
}



// ---------------------------- Print function ----------------------------
void European::print() const
{
    string cp = {};
    if(_payoff.get_flag() == 0){cout << "------- European Call -------" << endl;}
    else {cout << "------- European Put --------" << endl;}
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

// ---------------------------- Accessors ----------------------------
double European::get_strike()   const {return _payoff.get_strike();}
double European::get_maturity() const {return _T.get_value();}
double European::get_spot()     const {return _S.get_value();}
double European::get_vol()      const {return _sigma.get_value();}
double European::get_interest() const {return _r.get_value();}
double European::get_div()      const {return _q.get_value();}
double European::get_price()    const {return _price;}
double European::get_delta()    const {return _delta;}
double European::get_gamma()    const {return _gamma;}
double European::get_vega()     const {return _vega;}
double European::get_theta()    const {return _theta;}
double European::get_rho()      const {return _rho;}
double European::get_lambda()   const {return _lambda;}
double European::get_vanna()    const {return _vanna;}
double European::get_charm()    const {return _charm;}
double European::get_speed()    const {return _speed;}
double European::get_color()    const {return _color;}
double European::get_volga()    const {return _volga;}
double European::get_veta()     const {return _veta;}
double European::get_zomma()    const {return _zomma;}

