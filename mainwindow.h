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



    void on_weightKG_clicked();

    void on_weightPounds_clicked();

    void on_inputWeight_valueChanged(double arg1);

    void on_heightM_clicked();

    void on_heightFeet_clicked();

    void on_inputHeight_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    std::string weightLog = "";

    void spinBoxProperties(QString boxName, double singleStepVal, int decimalsVal);
    void setValueBox(QString boxName, double value);
    double valueConverter(double, double, char);

};
#endif // MAINWINDOW_H
