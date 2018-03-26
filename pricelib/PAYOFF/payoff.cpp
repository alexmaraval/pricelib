//
//  payoff.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 27.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "payoff.hpp"
// Constructor
Payoff::Payoff()
{
    _strat_ptr = 0;
}

Payoff::Payoff(const Strategy& s)
{
    _strat_ptr = s.clone();
}


// Copy Constructor
Payoff::Payoff(const Payoff& p)
{
    _strat_ptr = p._strat_ptr->clone();
}


// Operator= override
Payoff& Payoff::operator=(const Payoff& p)
{
    if(this != &p)
    {
        Strategy* tmp = p._strat_ptr->clone();
        delete _strat_ptr;
        _strat_ptr = tmp;
    }
    return *this;
}


// Virtual Destructor
Payoff::~Payoff()
{
    delete _strat_ptr;
}



// Payoff Function
double Payoff::operator()(double x) const
{
    return _strat_ptr->operator()(x);
}



// Accessors
double Payoff::get_strike() const
{
    return _strat_ptr->get_strike();
}

bool Payoff::get_flag() const
{
    return _strat_ptr->get_flag();
}
