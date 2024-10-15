#include "lab3.h"

#include <QApplication>

//Vectors for parallel convergence
QVector<double> Paralel_x_UAV;
QVector<double> Paralel_y_UAV;
QVector<double> Paralel_Teta_UAV;
QVector<double> Paralel_x_Target;
QVector<double> Paralel_y_Target;
QVector<double> Paralel_eps;
QVector<double> Paralel_phi;
QVector<double> Paralel_n_y;
QVector<double> Paralel_times;
QVector<double> Paralel_r_t;
double Paralel_r = 0;

//Vectors for proportional aiming
QVector<double> Proporc_x_UAV;
QVector<double> Proporc_y_UAV;
QVector<double> Proporc_Teta_UAV;
QVector<double> Proporc_x_Target;
QVector<double> Proporc_y_Target;
QVector<double> Proporc_eps;
QVector<double> Proporc_phi;
QVector<double> Proporc_n_y;
QVector<double> Proporc_times;
QVector<double> Proporc_r_t;
double Proporc_r = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab3 w;
    w.show();
    return a.exec();
}
