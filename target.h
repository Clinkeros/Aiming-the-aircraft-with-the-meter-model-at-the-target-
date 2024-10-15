#ifndef TARGET_H
#define TARGET_H

constexpr double V_t = 20, x_0_t = 2.1E3, y_0_t = 3.2E3, Teta_t = 0.2;

class Target
{
public:
    Target();
    double dx_dt(double V, double Teta);
    double dy_dt(double V, double Teta);
    ~Target();
};

#endif // TARGET_H
