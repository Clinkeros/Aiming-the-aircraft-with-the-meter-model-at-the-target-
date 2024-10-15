#ifndef UAV_H
#define UAV_H

constexpr double g = 9.81, V_u = 289, x_0_u = 3.2E3, y_0_u = 1.2E3, Teta_0_u = 0.05;

class UAV
{
public:
    UAV();
    double dTeta_dt(double Teta, double V, double n_y);
    double dx_dt(double V, double Teta);
    double dy_dt(double V, double Teta);
    ~UAV();
};

#endif // UAV_H
