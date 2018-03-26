//
//  option.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 22.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef option_hpp
#define option_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <boost/smart_ptr.hpp>
#include "random_generator.hpp"
#include "payoff.hpp"
#include "settings.hpp"
#include "parameters.hpp"
using namespace std;

class Option
{
private:
    
protected:

    double _price;
    Payoff _payoff;                 // Already Contains Strike and Call-Put Flag
    
public:
    
    virtual double auto_price() const = 0;
    virtual void print() const = 0;
    virtual double get_price() const = 0;
    virtual ~Option(){};
};

#endif /* option_hpp */
