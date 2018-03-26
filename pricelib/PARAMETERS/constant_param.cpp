//
//  constant_param.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 08.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "constant_param.hpp"

Const_param::Const_param(double v, double s, double e)
{
    _value = v;
    _start = s;
    _end = e;
}


Settings* Const_param::create() const
{
    return new Const_param();
}

Settings* Const_param::clone() const
{
    return new Const_param(*this);
}




double Const_param::integral(double t1, double t2) const
{
    return (t2-t1) * _value;
}

double Const_param::integral_square(double t1, double t2) const
{
    return(t2-t1) * _value*_value;
}



double Const_param::get_value() const
{
    return _value;
}

double Const_param::get_start() const
{
    return _start;
}

double Const_param::get_end() const
{
    return _end;
}



void Const_param::operator=(const Const_param& c)
{
    if(&c != this)
    {
        _value = c._value;
        _start = c._start;
        _end = c._end;
    }
}

void Const_param::operator=(double x)
{
    if(_value != x)
    {
        _value = x;
    }
}
