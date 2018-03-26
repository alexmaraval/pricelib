//
//  brownian_path.cpp
//  pricelib
//
//  Created by Alexandre Maraval on 25.01.18.
//  Copyright © 2018 Alexandre Maraval. All rights reserved.
//

#include "brownian_path.hpp"

Path::Path(double start, double drift, double diffusion, string method, double T, double N)
{
    _start = start;
    _drift = drift;
    _diffusion = diffusion;
    _T = T;
    _N = N;
    _dt = _T / _N;
    _path.resize(T+1);
    _antipath.resize(T+1);
    
    _path[0] = _start;
    for(int i=1; i<=_T; i++)
    {
        Normal Z(0,1,"m");
            _path[i] =     _path[i-1] * (1 + _drift * _dt + _diffusion * sqrt(_dt) *  Z.get_x());
        _antipath[i] = _antipath[i-1] * (1 + _drift * _dt + _diffusion * sqrt(_dt) * -Z.get_x());
        if (_method == "milstein")
        {
                _path[i] +=     _path[i-1] * (0.5 * _diffusion * _dt * (Z.get_x() * Z.get_x()-1));
            _antipath[i] += _antipath[i-1] * (0.5 * _diffusion * _dt * (Z.get_x() * Z.get_x()-1));
        }
    }
}

void Path::get_path(vector<double> &p)
{
    for(int i=0; i<_path.size(); i++)
    {
        p[i] = _path[i];
    }
}

void Path::get_antipath(vector<double> &ap)
{
    for(int i=0; i<_antipath.size(); i++)
    {
        ap[i] = _antipath[i];
    }
}
