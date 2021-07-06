#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void weightCalc();

private slots:
    // void on_weightInput_valueChanged(const QString &arg1);


    void on_ageInput_valueChanged(double arg1);

    void on_weightInput_valueChanged(double arg1);

    void on_ageInput_valueChanged(int arg1);

    void on_heightInput_valueChanged(double arg1);

    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
    void bmiCalculator();
    void weightCalc(int arg1);
    void valuesCheckpoint();
    void genderRadioToggle();
};
#endif // MAINWINDOW_H
