//
//  brownian_path.hpp
//  pricelib
//
//  Created by Alexandre Maraval on 25.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#ifndef brownian_path_hpp
#define brownian_path_hpp

#include <stdio.h>
#include "option.hpp"
#include "random_generator.hpp"
using namespace std;

class Path
{
private:
    double _start;              // Starting point of the SDE
    double _drift;              // drift coefficient in the SDE
    double _diffusion;          // diffusion coefficient in the SDE
    string _method;             // Euler or Milstein Scheme
    
    double _T;                  // Total time of the path
    double _dt;                 // Size of the time step
    double _N;                  // Number of time steps
    
    vector<double> _path;
    vector<double> _antipath;
    
public:
    Path(double start = 0, double drift = 0, double diffusion = 1, string method = "euler", double T = 0, double N = 0);
    
    void get_path(vector<double> &p);
    void get_antipath(vector<double> &ap);
};

#endif /* brownian_path_hpp */
