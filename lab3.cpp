#include "lab3.h"
#include "F:\qcustomplot\qcustomplot.h"
#include "./ui_lab3.h"
#include "QString"

#include "Paralel.h"
#include "Proporc.h"

// Vectors for parallel convergence
extern QVector<double> Paralel_x_UAV;
extern QVector<double> Paralel_y_UAV;
extern QVector<double> Paralel_Teta_UAV;
extern QVector<double> Paralel_x_Target;
extern QVector<double> Paralel_y_Target;
extern QVector<double> Paralel_eps;
extern QVector<double> Paralel_phi;
extern QVector<double> Paralel_n_y;
extern QVector<double> Paralel_r_t;
extern QVector<double> Paralel_times;
extern double Paralel_r;

// Vectors for proportional aiming
extern QVector<double> Proporc_x_UAV;
extern QVector<double> Proporc_y_UAV;
extern QVector<double> Proporc_Teta_UAV;
extern QVector<double> Proporc_x_Target;
extern QVector<double> Proporc_y_Target;
extern QVector<double> Proporc_eps;
extern QVector<double> Proporc_phi;
extern QVector<double> Proporc_n_y;
extern QVector<double> Proporc_r_t;
extern QVector<double> Proporc_times;
extern double Proporc_r;

Lab3::Lab3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab3)
{
    ui->setupUi(this);
}

Lab3::~Lab3()
{
    delete ui;
}

// Выполнить расчет
void Lab3::on_pushButton_clicked()
{
    if (ui -> radioButton -> isChecked())
    {
        Paralel(0.05, 0.0, 0.0);
        Proporc(0.049, 0.0, 0.0);
        QString time_par = QString::number(Paralel_times.last());
        QString time_pro = QString::number(Proporc_times.last());
        QString r_par = QString::number(Paralel_r);
        QString r_pro = QString::number(Proporc_r);
        ui -> textEdit_3 -> append("Расчет выполнен");
        ui -> textEdit_3 -> append("Время попадания для метода параллельного наведения: " + time_par + " с");
        ui -> textEdit_3 -> append("Промах для метода параллельного наведения: " + r_par + " м");
        ui -> textEdit_3 -> append("Время попадания для метода пропорцианального наведения: " + time_pro + " с");
        ui -> textEdit_3 -> append("Промах для метода пропорцианального наведения: " + r_pro + " м");
        on_pushButton_7_clicked();
    }
    if (ui -> radioButton_2 -> isChecked())
    {
        Paralel(0.05, 0.0, 0.5);
        Proporc(0.049, 0.0, 0.5);
        QString time_par = QString::number(Paralel_times.last());
        QString time_pro = QString::number(Proporc_times.last());
        QString r_par = QString::number(Paralel_r);
        QString r_pro = QString::number(Proporc_r);
        ui -> textEdit_3 -> append("Расчет выполнен");
        ui -> textEdit_3 -> append("Время попадания для метода параллельного наведения: " + time_par + " с");
        ui -> textEdit_3 -> append("Промах для метода параллельного наведения: " + r_par + " м");
        ui -> textEdit_3 -> append("Время попадания для метода пропорцианального наведения: " + time_pro + " с");
        ui -> textEdit_3 -> append("Промах для метода пропорцианального наведения: " + r_pro + " м");
        on_pushButton_7_clicked();
    }
}

// Графики наклон траектории
void Lab3::on_pushButton_2_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_times, Paralel_Teta_UAV);
    ui -> widget -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("θ, рад");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 3);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_times, Proporc_Teta_UAV);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("θ, рад");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(0, 3.5);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();
}

// Графики угла упреждение
void Lab3::on_pushButton_3_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_times, Paralel_phi);
    ui -> widget -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("φ, рад");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 2.5);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_times, Proporc_phi);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("φ, рад");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(-7, 2.5);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();

}

// Графики x
void Lab3::on_pushButton_4_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph(0) -> setData(Paralel_times, Paralel_x_UAV);
    ui -> widget -> graph(0) -> setPen(QPen(Qt::blue));
    ui -> widget -> addGraph();
    ui -> widget -> graph(1) -> setData(Paralel_times, Proporc_x_Target);
    ui -> widget -> graph(1) -> setPen(QPen(Qt::red));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("x, м");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 4400);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph(0) -> setData(Proporc_times, Proporc_x_UAV);
    ui -> widget_2 -> graph(0) -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph(1) -> setData(Proporc_times, Proporc_x_Target);
    ui -> widget_2 -> graph(1) -> setPen(QPen(Qt::red));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("x, м");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(0, 4800);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();
}

// Графики уголф наклонф линии визирования
void Lab3::on_pushButton_5_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_times, Paralel_eps);
    ui -> widget -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("ε, рад");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 3);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_times, Proporc_eps);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("ε, рад");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(-3.5, 3.5);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();

}

// Графики перегрузки
void Lab3::on_pushButton_6_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_times, Paralel_n_y);
    ui -> widget -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("n_y");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(-5, 20);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_times, Proporc_n_y);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("n_y");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(-5, 10);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();
}

// Графики траектории
void Lab3::on_pushButton_7_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    QCPCurve *Curve = new QCPCurve(ui -> widget -> xAxis, ui -> widget -> yAxis);

    Curve -> setData(Paralel_x_UAV, Paralel_y_UAV);
    Curve -> setPen(QPen(Qt::blue));
    Curve -> setName("ЛА");
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_x_Target, Paralel_y_Target);
    ui -> widget -> graph() -> setPen(QPen(Qt::red));
    ui -> widget -> graph() -> setName("Цель");
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("x, м");
    ui -> widget -> yAxis -> setLabel("y, м");
    ui -> widget -> xAxis -> setRange(0, 4400);
    ui -> widget -> yAxis -> setRange(0, 3300);
    ui -> widget -> legend -> setVisible(true);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    QCPCurve *Curve2 = new QCPCurve(ui -> widget_2 -> xAxis, ui -> widget_2 -> yAxis);

    Curve2 -> setData(Proporc_x_UAV, Proporc_y_UAV);
    Curve2 -> setPen(QPen(Qt::blue));
    Curve2 -> setName("ЛА");
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_x_Target, Proporc_y_Target);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::red));
    ui -> widget_2 -> graph() -> setName("Цель");
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("x, м");
    ui -> widget_2 -> yAxis -> setLabel("y, м");
    ui -> widget_2 -> xAxis -> setRange(0, 4800);
    ui -> widget_2 -> yAxis -> setRange(0, 3400);
    ui -> widget_2 -> legend -> setVisible(true);

    ui -> widget_2 -> replot();
}

// Графики y
void Lab3::on_pushButton_8_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph(0) -> setData(Paralel_times, Paralel_y_UAV);
    ui -> widget -> graph(0) -> setPen(QPen(Qt::blue));
    ui -> widget -> graph(0) -> setName("ЛА");
    ui -> widget -> addGraph();
    ui -> widget -> graph(1) -> setData(Paralel_times, Proporc_y_Target);
    ui -> widget -> graph(1) -> setPen(QPen(Qt::red));
    ui -> widget -> graph(1) -> setName("Цель");
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("y, м");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 3300);
    ui -> widget -> legend -> setVisible(true);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph(0) -> setData(Proporc_times, Proporc_y_UAV);
    ui -> widget_2 -> graph(0) -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> graph(0) -> setName("ЛА");
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph(1) -> setData(Proporc_times, Proporc_y_Target);
    ui -> widget_2 -> graph(1) -> setPen(QPen(Qt::red));
    ui -> widget_2 -> graph(1) -> setName("Цель");
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("y, м");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(0, 3400);
    ui -> widget_2 -> legend -> setVisible(true);

    ui -> widget_2 -> replot();
}

// Графики расстояния до цели
void Lab3::on_pushButton_9_clicked()
{
    // Графики для параллельного наведения
    ui -> widget -> clearPlottables();
    ui -> widget -> addGraph();
    ui -> widget -> graph() -> setData(Paralel_times, Paralel_r_t);
    ui -> widget -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget -> xAxis -> setLabel("t, с");
    ui -> widget -> yAxis -> setLabel("r, м");
    ui -> widget -> xAxis -> setRange(0, 20);
    ui -> widget -> yAxis -> setRange(0, 2730);
    ui -> widget -> legend -> setVisible(false);

    ui -> widget -> replot();

    // Графики для пропорционального наведения
    ui -> widget_2 -> clearPlottables();
    ui -> widget_2 -> addGraph();
    ui -> widget_2 -> graph() -> setData(Proporc_times, Proporc_r_t);
    ui -> widget_2 -> graph() -> setPen(QPen(Qt::blue));
    ui -> widget_2 -> setInteraction(QCP::iRangeDrag, true);
    ui -> widget_2 -> setInteraction(QCP::iRangeZoom, true);
    ui -> widget_2 -> axisRect() -> setRangeDrag(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> axisRect() -> setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui -> widget_2 -> xAxis -> setLabel("t, с");
    ui -> widget_2 -> yAxis -> setLabel("r, м");
    ui -> widget_2 -> xAxis -> setRange(0, 20);
    ui -> widget_2 -> yAxis -> setRange(0, 2880);
    ui -> widget_2 -> legend -> setVisible(false);

    ui -> widget_2 -> replot();
}

