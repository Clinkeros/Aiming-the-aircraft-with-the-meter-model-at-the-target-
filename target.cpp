#include "target.h"
#include "cmath"

Target::Target() {}


double Target::dx_dt(double V, double Teta)
{
    double x;

    x = V * cos(Teta);

    return x;
}

double Target::dy_dt(double V, double Teta)
{
    double y;

    y = V * sin(Teta);

    return y;
}

Target::~Target() {}
