#include <cmath>
#include <QVector>

#include "uav.h"
#include "target.h"
#include "Proporc.h"
#include "Noise.h"

extern QVector<double> Proporc_x_UAV;
extern QVector<double> Proporc_y_UAV;
extern QVector<double> Proporc_Teta_UAV;
extern QVector<double> Proporc_x_Target;
extern QVector<double> Proporc_y_Target;
extern QVector<double> Proporc_eps;
extern QVector<double> Proporc_phi;
extern QVector<double> Proporc_n_y;
extern QVector<double> Proporc_times;
extern QVector<double> Proporc_r_t;
extern double Proporc_r;

void Proporc(double Teta_0, double M, double stddev)
{
    // Отчистка векторов от предыдущих расчетов
    Proporc_x_UAV.clear();
    Proporc_y_UAV.clear();
    Proporc_Teta_UAV.clear();
    Proporc_x_Target.clear();
    Proporc_y_Target.clear();
    Proporc_eps.clear();
    Proporc_phi.clear();
    Proporc_n_y.clear();
    Proporc_times.clear();
    Proporc_r_t.clear();
    Proporc_r = 1E50;

    // Начальные данные
    double x_u = x_0_u, y_u = y_0_u, Teta_u = Teta_0;
    double x_t = x_0_t, y_t = y_0_t, n_y = 1;
    double r = 1E50, eps_t = 0, phi_t = 0;
    double sigma_eps = 0.006981, sigma_r = 3.4;

    UAV uav;
    Target target;

    // Данные для интегрирования
    double t = 0, t_l = 2, h = 0.0001;

    //navigation constant
    double k = 3;

    // Initialization of initial data
    Proporc_x_UAV.push_back(x_0_u);
    Proporc_y_UAV.push_back(y_0_u);
    Proporc_Teta_UAV.push_back(Teta_0_u);
    Proporc_x_Target.push_back(x_0_t);
    Proporc_y_Target.push_back(y_0_t);
    Proporc_n_y.push_back(n_y);
    Proporc_times.push_back(0);



    // Calculations up to time tl
    while (r > 1)
    {
        double x_temp = 0, y_temp = 0, Teta_temp = 0;

        if (t < t_l)
        {
            // Calculating distance, slope of the line of sight and anticipation angle
            r = sqrt(pow((x_t - x_u),2) + pow((y_t - y_u),2)) + noise(M, stddev)*sigma_r;
            eps_t = atan2((y_t - y_u),(x_t - x_u)) + noise(M, stddev)*sigma_eps;
            phi_t = eps_t - Teta_u;
            n_y = 1;

            // Calculation for LA
            Teta_temp = uav.dTeta_dt(Teta_u, V_u, n_y);
            x_temp = uav.dx_dt(V_u, Teta_u);
            y_temp = uav.dy_dt(V_u, Teta_u);

            Teta_u = Teta_u + h*Teta_temp;
            x_u = x_u + h*x_temp;
            y_u = y_u + h*y_temp;

            // Calculation for target
            x_temp = target.dx_dt(V_t, Teta_t);
            y_temp = target.dy_dt(V_t, Teta_t);

            x_t = x_t + h*x_temp;
            y_t = y_t + h*y_temp;

            // Result record
            Proporc_Teta_UAV.push_back(Teta_u);
            Proporc_x_UAV.push_back(x_u);
            Proporc_y_UAV.push_back(y_u);
            Proporc_x_Target.push_back(x_t);
            Proporc_y_Target.push_back(y_t);
            Proporc_eps.push_back(eps_t);
            Proporc_phi.push_back(phi_t);
            Proporc_n_y.push_back(n_y);
            Proporc_r_t.push_back(r);
        }
        else
        {
            // Calculating distance, slope of the line of sight and anticipation angle
            r = sqrt(pow((x_t - x_u),2) + pow((y_t - y_u),2)) + noise(M, stddev) * sigma_r;
            eps_t = atan2((y_t - y_u),(x_t - x_u)) + noise(M, stddev) * sigma_eps;
            phi_t = eps_t - Teta_u;
            n_y = cos(Teta_u) + k * V_u * ((-V_t * sin(eps_t) + V_u * sin(phi_t))/r) /g;

            // Calculation for LA
            Teta_temp = uav.dTeta_dt(Teta_u, V_u, n_y);
            x_temp = uav.dx_dt(V_u, Teta_u);
            y_temp = uav.dy_dt(V_u, Teta_u);

            Teta_u = Teta_u + h*Teta_temp;
            x_u = x_u + h*x_temp;
            y_u = y_u + h*y_temp;

            // Calculation for target
            x_temp = target.dx_dt(V_t, Teta_t);
            y_temp = target.dy_dt(V_t, Teta_t);
            x_t = x_t + h*x_temp;
            y_t = y_t + h*y_temp;

            // Result record
            Proporc_Teta_UAV.push_back(Teta_u);
            Proporc_x_UAV.push_back(x_u);
            Proporc_y_UAV.push_back(y_u);
            Proporc_x_Target.push_back(x_t);
            Proporc_y_Target.push_back(y_t);
            Proporc_eps.push_back(eps_t);
            Proporc_phi.push_back(phi_t);
            Proporc_n_y.push_back(n_y);
            Proporc_r_t.push_back(r);
        }


        t += h;

        Proporc_times.push_back(t);

        Proporc_r = r;

        if (t>1000)
            break;
    }
}
