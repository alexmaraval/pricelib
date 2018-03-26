//
//  settings.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 31.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef settings_hpp
#define settings_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <boost/smart_ptr.hpp>
using namespace std;

class Settings
{
private:
protected:
public:
    virtual Settings* create() const = 0;
    virtual Settings* clone() const = 0;
    virtual ~Settings(){};
    
    virtual double get_value() const = 0;
    virtual double integral(double t1, double t2) const = 0;
    virtual double integral_square(double t1, double t2) const = 0;
    
//    virtual void operator=(const Settings& s) = 0;              // is it a good idea ?
};

#endif /* settings_hpp */
