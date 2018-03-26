//
//  payoff.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef payoff_hpp
#define payoff_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <boost/smart_ptr.hpp>
#include "strategy.hpp"
using namespace std;

class Payoff
{
private:
    Strategy* _strat_ptr;
    
public:
    Payoff();
    Payoff(const Strategy& s);            // Constructor
    Payoff(const Payoff &p);                    // Copy Constructor
    Payoff& operator=(const Payoff& p);         // Operator= override
    virtual ~Payoff();                          // Virtual Destructor
    double operator()(double x) const;          // payoff function
    
    double get_strike() const;
    bool get_flag() const;
};

#endif /* payoff_hpp */
