//
//  main.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 13.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include <iostream>
#include "digital.hpp"
#include "binomial_tree.hpp"
#include "brownian_path.hpp"
#include "european.hpp"
#include "option.hpp"
#include "random_generator.hpp"
#include "payoff.hpp"
#include "strategy.hpp"
#include "vanilla.hpp"
#include "parameters.hpp"
#include "constant_param.hpp"
#include "settings.hpp"

using namespace std;

int main()
{
    Const_param K = 100;
    Vanilla call_payoff(K,0);
    Vanilla put_payoff(K,1);
    
    Const_param T = 2;
    Const_param S0 = 102;
    Const_param sigma = 0.25;
    Const_param r = 0.05;
    Const_param q = 0;
    
    string model = "bs";
    
    European Call(T, S0, sigma, r, q, call_payoff, model);           // Have to delete K from being a member of the European and Binary class, it's already in Payoff
    European  Put(T, S0, sigma, r, q, put_payoff, model);
    Call.print();
    Put.print();
//    
//    Digital call(K, T, S0, sigma, r, q, 0);
//    Digital put(K, T, S0, sigma, r, q, 1);
//    call.print();
//    put.print();
    
    return 0;
}
