//
//  vanilla.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "vanilla.hpp"

Vanilla::Vanilla(double k, bool cpflag)
{
    _strike = k;
    _cpflag = cpflag;
}

Vanilla::Vanilla(Parameter K, bool cpflag)
{
    _strike = K.get_value();
    _cpflag = cpflag;
}



Vanilla* Vanilla::clone() const
{
    return new Vanilla(*this);
}

Vanilla* Vanilla::create() const
{
    return new Vanilla();
}




void Vanilla::set_strike(double new_k)
{
    this->_strike = new_k;
}

void Vanilla::set_flag(bool new_flag)
{
    this->_cpflag = new_flag;
}




double Vanilla::get_strike() const
{
    return _strike;
}

bool Vanilla::get_flag() const
{
    return _cpflag;
}




double Vanilla::operator()(double s) const 
{
    return (1-_cpflag)*fmax(s-_strike,0) + _cpflag*fmax(_strike-s,0);
}
