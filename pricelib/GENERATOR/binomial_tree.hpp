//
//  binomial_tree.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef binomial_tree_hpp
#define binomial_tree_hpp

#include <stdio.h>
#include "option.hpp"
using namespace std;

class Binomial_tree
{
private:
    double _S0;
    double _K;
    double _T;
    double _sigma;
    double _r;
    
    double _u;
    double _d;
    double _p;
    double _N;
    double _dt;
    
    bool _cpflag;           // 0 = Call, 1 = Put
    bool _euramflag;        // 0 = European, 1 = American
    double _price;
        
protected:
    
public:
    Binomial_tree(double S = 0, double K = 0, double T = 0, double sigma = 0, double r = 0, double N = 0, bool cpflag = 0, bool euramflag = 0);
    double payoff(double x);
    double get_stock(int i, int j);
    double crr_price(double S, double K, double T, double sigma, double r, double N, bool cpflag, bool euramflag);
    
};

#endif /* binomial_tree_hpp */
