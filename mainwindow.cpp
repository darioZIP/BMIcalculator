#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
#include <cmath>
#include <csv.hpp>

// BMI data taken from
// https://www.calculator.net/bmi-calculator.html

// Declaring variables. QPair holding user input but that can easily be changed.
int ageMeasure = 0;
QPair<double, double> weightMeasure; // first = KG | second = Pound
QPair<double, double> heightMeasure; // first = CM | second = Feet

// Bool for proper unit conversion
bool weightToggle; // 0 = KG | 1 = Pounds
bool heightToggle; // 0 = CM | 1 = Feet

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

ui->setupUi(this);




}

// Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

// --------- Weight Radio Toggle
void MainWindow::on_weightKG_clicked()
{
 weightToggle = 0;
 valuesConverter();
 ui->weightInput->setValue(weightMeasure.first);
}

void MainWindow::on_weightPounds_clicked()
{
   weightToggle = 1;
   valuesConverter();
   ui->weightInput->setValue(weightMeasure.second);
}

// ------------------------------------------------------------

// Used to convert values when radio buttons are clicked.
void MainWindow::valuesConverter() {

    // KG to Pounds
    if (weightToggle == 1) {
        weightMeasure.first = weightMeasure.second*0.45359237;
    }

    // Pounds to KG
    else {
    weightMeasure.second = weightMeasure.first*2.20462;
    }

    // CM to feet
    if (heightToggle == 1) {
        heightMeasure.second = weightMeasure.first*0.45359237;
    }
    // Feet to CM
    else {
    weightMeasure.first = weightMeasure.second*30.48;
    }

    valuesCheckpoint();
}






//---------------------------------------

void MainWindow::on_ageInput_valueChanged(int arg1)
{
   ageMeasure = arg1;
   genderRadioToggle();
   valuesCheckpoint();
}

void MainWindow::genderRadioToggle(){

    if (ageMeasure <18) {
        ui->maleRadio->setEnabled(true);
        ui->femaleRadio->setEnabled(true);
    }
    else {
    ui->maleRadio->setEnabled(false);
    ui->femaleRadio->setEnabled(false);
    }
}


void MainWindow::on_heightInput_valueChanged(double arg1)
{
    if (ui->heightcm->isEnabled()) {
        heightMeasure.first = arg1;
    }

    else {
        heightMeasure.second = arg1;
    }

    valuesCheckpoint();
}

// Signal for Age, Weight and Height. Will trigger the valuesCheckpoint.
void MainWindow::on_weightInput_valueChanged(double arg1)
{

if (ui->weightKG->isEnabled()) {
 weightMeasure.first = arg1;
}

else {
 weightMeasure.second = arg1;
}

    valuesCheckpoint();

}





// Checking if value of age, weight and height are different than zero.
// If yes, bmiCalculator is executed.
void MainWindow::valuesCheckpoint() {

    if ((weightMeasure.first || weightMeasure.second != 0.00) && (heightMeasure.first || heightMeasure.second != 0.00) && (ageMeasure != 0.00)) {
        bmiCalculator();
    }

}




void MainWindow::bmiCalculator() {



   double bmiResult = weightMeasure.first / (heightMeasure.first*heightMeasure.first);
   ui->bmiLabel->setText(QString::number(std::trunc(bmiResult)));
}







