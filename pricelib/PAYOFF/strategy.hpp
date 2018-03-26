//
//  strategy.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef strategy_hpp
#define strategy_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <boost/smart_ptr.hpp>
#include "parameters.hpp"
using namespace std;

class Strategy
{
private:
protected:
public:
    virtual Strategy* create() const = 0;               // virtual constructor
    virtual Strategy* clone()  const = 0;               // virtual copy constructor
    virtual ~Strategy(){};                              // virtual destructor
    virtual double operator()(double s) const = 0;      // pure virtual payoff, override operator instead of creating a payof() member function for clarity
    
    virtual double get_strike() const = 0;
    virtual bool get_flag() const = 0;
};

#endif /* strategy_hpp */
