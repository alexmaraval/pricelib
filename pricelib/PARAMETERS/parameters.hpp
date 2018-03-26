//
//  parameters.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 31.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef parameters_hpp
#define parameters_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <boost/smart_ptr.hpp>
#include "settings.hpp"

class Parameter
{
private:
    Settings* _settings_ptr;
protected:
public:
    Parameter();
    Parameter(const Settings& s);
    Parameter(const Parameter& p);
    virtual ~Parameter();
    virtual Parameter& operator=(const Parameter& p);
    
    // need virtual or not ? not sure, polymorphism will be done by the pointer not inheritance from Parameter class
    virtual double mean(double t1, double t2) const;
    virtual double root_mean_square(double t1, double t2) const;
    virtual double integral(double t1, double t2) const;
    virtual double integral_square(double t1, double t2) const;
    virtual double get_value() const;
};

#endif /* parameters_hpp */
