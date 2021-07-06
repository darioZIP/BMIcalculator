#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
#include <cmath>

// BMI data taken from
// https://www.calculator.net/bmi-calculator.html?ctype=metric&cage=25&csex=m&cheightfeet=5&cheightinch=10&cpound=160&cheightmeter=180&ckg=65&printit=0

// Initializing standard values for double values.
// Will be replaced to a QVector of pairs afterwards.
double weightMeasure = 0;
double ageMeasure = 0;
double heightMeasure = 0;





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

ui->setupUi(this);
//connect(ui->weightInput, SIGNAL(valueChanged(double)), this, MainWindow::weightCalc());
}



// Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}






// Signal for Age, Weight and Height. Will trigger the valuesCheckpoint.
void MainWindow::on_weightInput_valueChanged(double arg1)
{
    weightMeasure = arg1;
    valuesCheckpoint();

}


void MainWindow::on_ageInput_valueChanged(int arg1)
{
   ageMeasure = arg1;
   if (ageMeasure <18) {
       ui->maleRadio->setChecked(false);
   }
   else {
   ui->maleRadio->setChecked(true);
   }
   valuesCheckpoint();
}


void MainWindow::on_heightInput_valueChanged(double arg1)
{
    heightMeasure = arg1;
    valuesCheckpoint();
}

// Checking if value of age, weight and height are different than zero.
// If yes, bmiCalculator is executed.
void MainWindow::valuesCheckpoint() {


    if (weightMeasure != 0.00 && heightMeasure != 00)  {
        bmiCalculator();
    }

}

void MainWindow::bmiCalculator() {
   double bmiResult = weightMeasure / (heightMeasure*heightMeasure);
   ui->bmiLabel->setText(QString::number(std::trunc(bmiResult)));

}

void MainWindow::on_calculateButton_clicked()
{
    bmiCalculator();
}

