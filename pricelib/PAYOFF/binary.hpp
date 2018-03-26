//
//  binary.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 12.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef binary_hpp
#define binary_hpp

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

class Binary : public Strategy
{
protected:
    double _strike;
    bool _cpflag;
public:
    Binary(double k = 0, bool cpflag = 0);          // Constructor
    Binary(Parameter K, bool cpflag);               // Constructor with a Parameter object
    
    virtual Binary* create() const;                 // Virtual Constructor
    virtual Binary* clone()  const;                 // Virtual Copy Constructor
    
//    virtual ~Binary();                              // Virtual Destructor
    
    void set_strike(double new_k);
    void set_flag(bool new_flag);
    
    double get_strike() const;
    bool get_flag() const;
    
    virtual double operator()(double s) const;      // payoff function
};

#endif /* binary_hpp */
