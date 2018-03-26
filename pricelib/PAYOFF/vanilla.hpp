//
//  vanilla.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef vanilla_hpp
#define vanilla_hpp

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

class Vanilla : public Strategy
{
protected:
    double _strike;
    bool _cpflag;
public:
    Vanilla(double k = 0, bool cpflag = 0);         // Constructor
    Vanilla(Parameter K, bool cpflag);              // Constructor with a Parameter object
    
    virtual Vanilla* create() const;                // Virtual Constructor
    virtual Vanilla* clone()  const;                // Virtual Copy Constructor
    
//    virtual ~Vanilla();                           // Virtual Destructor
    
    void set_strike(double new_k);
    void set_flag(bool new_flag);
    
    double get_strike() const;
    bool get_flag() const;
    
    virtual double operator()(double s) const;      // payoff function
};

#endif /* vanilla_hpp */
