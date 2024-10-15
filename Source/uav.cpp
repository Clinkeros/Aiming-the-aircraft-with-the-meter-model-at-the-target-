#include "../../Lab3/Headers/uav.h"
#include "cmath"

UAV::UAV() {}

double UAV::dTeta_dt(double Teta, double V, double n_y)
{
    Teta = (g / V) * (n_y - cos(Teta));
    return Teta;
}

double UAV::dx_dt(double V, double Teta)
{
    double x;

    x = V * cos(Teta);

    return x;
}

double UAV::dy_dt(double V, double Teta)
{
    double y;

    y = V * sin(Teta);

    return y;
}

UAV::~UAV() {}
