#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
// BMI data taken from
// https://www.calculator.net/bmi-calculator.html?ctype=metric&cage=25&csex=m&cheightfeet=5&cheightinch=10&cpound=160&cheightmeter=180&ckg=65&printit=0
int weightMeasure = 0;





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

ui->setupUi(this);
//connect(ui->weightInput, SIGNAL(valueChanged(double)), this, MainWindow::weightCalc());
}

void MainWindow::weightCalc(int arg1) {
weightMeasure = arg1;
ui->bmiLabel->setText("sex");

}


MainWindow::~MainWindow()
{
    delete ui;
}


void bmiCalculator() {
//
}



void MainWindow::on_ageInput_valueChanged(double arg1)
{
QString numString = QString::number(arg1);
 ui->bmiLabel->setText(numString);
}

