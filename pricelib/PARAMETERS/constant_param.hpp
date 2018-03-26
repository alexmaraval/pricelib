//
//  constant_param.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 08.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef constant_param_hpp
#define constant_param_hpp

#include <stdio.h>
#include "settings.hpp"

class Const_param : public Settings
{
protected:
    double _value;
    double _start;
    double _end;
public:
    Const_param(double v = 0, double s = 0, double e = 1);
    
    Settings* create() const;
    Settings* clone() const;
    
    double integral(double t1, double t2) const;
    double integral_square(double t1, double t2) const;
    
    double get_value() const;
    double get_start() const;
    double get_end() const;
    
    void operator=(const Const_param& c);
    void operator=(double x);
};

#endif /* constant_param_hpp */
