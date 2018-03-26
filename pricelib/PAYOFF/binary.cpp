//
//  binary.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 12.02.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "binary.hpp"

Binary::Binary(double k, bool cpflag)
{
    _strike = k;
    _cpflag = cpflag;
}

Binary::Binary(Parameter K, bool cpflag)
{
    _strike = K.get_value();
    _cpflag = cpflag;
}



Binary* Binary::clone() const
{
    return new Binary(*this);
}

Binary* Binary::create() const
{
    return new Binary();
}




void Binary::set_strike(double new_k)
{
    this->_strike = new_k;
}

void Binary::set_flag(bool new_flag)
{
    this->_cpflag = new_flag;
}





double Binary::get_strike() const
{
    return _strike;
}

bool Binary::get_flag() const
{
    return _cpflag;
}





double Binary::operator()(double s) const
{
    return (1-_cpflag)*fmax(s-_strike,0) + _cpflag*fmax(_strike-s,0);
}
