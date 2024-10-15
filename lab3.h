#ifndef LAB3_H
#define LAB3_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Lab3;
}
QT_END_NAMESPACE

class Lab3 : public QMainWindow
{
    Q_OBJECT

public:
    Lab3(QWidget *parent = nullptr);
    ~Lab3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Lab3 *ui;
};
#endif // LAB3_H
