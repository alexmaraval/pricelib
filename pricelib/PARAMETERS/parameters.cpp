//
//  parameters.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 31.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "parameters.hpp"

Parameter::Parameter()
{
    _settings_ptr = 0;
}

Parameter::Parameter(const Settings& s)
{
    _settings_ptr = s.clone();
}


Parameter::Parameter(const Parameter& p)
{
    _settings_ptr = p._settings_ptr->clone();
}


Parameter::~Parameter()
{
    delete _settings_ptr;
}


Parameter& Parameter::operator=(const Parameter& p)
{
    if(this != &p)
    {
        delete _settings_ptr;
        _settings_ptr = p._settings_ptr->clone();
    }
    return *this;
}



double Parameter::mean(double t1, double t2) const
{
    return _settings_ptr->integral_square(t1, t2) / (t2 - t1);
}

double Parameter::root_mean_square(double t1, double t2) const
{
    return _settings_ptr->integral_square(t1, t2) / (t2 - t1);
}

double Parameter::integral(double t1, double t2) const
{
    return _settings_ptr->integral(t1,t2);
}

double Parameter::integral_square(double t1, double t2) const
{
    return _settings_ptr->integral_square(t1, t2);
}

double Parameter::get_value() const
{
    return _settings_ptr->get_value();
}
