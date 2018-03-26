//
//  binomial_tree.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "binomial_tree.hpp"
using namespace std;

Binomial_tree::Binomial_tree(double S, double K, double T, double sigma, double r, double N, bool cpflag, bool euramflag)
{
    _S0 = S;
    _K = K;
    _T = T;
    _sigma = sigma;
    _r = r;
    _N = N;
    _dt = _T/_N;

    _u = exp(_sigma * sqrt(_dt));
    _d = exp(-_sigma * sqrt(_dt));
    _p = (exp(_r) - _d) / (_u - _d);

    _cpflag = cpflag;
    _euramflag = euramflag;

    _price = crr_price(_S0, _K, _T, _sigma, _r, _N, _cpflag, _euramflag);
}

double Binomial_tree::payoff(double x)
{
    return (1-_cpflag) * fmax(x-_K,0) + _cpflag * fmax(_K-x,0);
}


double Binomial_tree::get_stock(int i, int j)
{
    return _S0 * pow(_u,i) * pow(_d,j);
}

double Binomial_tree::crr_price(double S, double K, double T, double sigma, double r, double N, bool cpflag, bool euramflag) // 1D implementation !
{
    if(!euramflag)
    {
        double  *ptr = new double[_N+1];
        for(int i=0; i<=N; i++)                                                             // Fill up Last Layer of the Tree : Payoff Prices at Maturity
        {
            *(ptr+i)= payoff(get_stock(i,_N-i));
        }
                                                                                            // Dynamic Programming : Go backwards in time to compute the value of the preceding node
        for(int i=_N-1; i>=0; i--)                                                          // Start with Layer N-1 and fill it using Layer N
        {                                                                                   // Actually overrwiting the *ptr repesenting the Layer (-> 1D) avoiding to store all the Layers
            for(int j=0; j<=i; j++)
            {
                *(ptr+j) = (_p * (*(ptr+j+1)) + (1-_p) * (*(ptr+j))) * exp(-_r*_dt);        // V_i,j = e^(-r*dt) * ( p * V_i+1,j+1  +  (1-p) * V_i+1,j )
            }
        }
        return *ptr;
    }
    else
    {
        double  *ptr = new double[_N+1];
        for(int i=0; i<=N; i++)
        {
            *(ptr+i)= payoff(get_stock(i,_N-i));
        }
        
        for(int i=_N-1; i>=0; i--)
        {
            for(int j=0; j<=i; j++)
            {
                *(ptr+j) = fmax((_p * (*(ptr+j+1)) + (1-_p) * (*(ptr+j))) * exp(-_r*_dt), payoff(get_stock(i,j)));  // Only difference with European case, we take
            }                                                                                                       // MAX( V_i,j = e^(-r*dt) * ( p * V_i+1,j+1  +  (1-p) * V_i+1,j ) , Payoff(S_i,j) )
        }
        return *ptr;
    }
}
