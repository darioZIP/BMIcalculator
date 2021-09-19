#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
#include <cmath>
#include <csv.hpp>
#include <QDesktopServices>

// Links from clickable buttons
QString homepage = "https://github.com/dariopedroniDEV/BMIcalculator";
QString donatePage = "https://dariopedroni.dev/donate/";



// BMI data taken from
// https://www.calculator.net/bmi-calculator.html

// Declaring variables. QPair holding user input but that can easily be changed.
int ageValue = 0;

// Storing values of QSpinBoxes
double weightValue = 0;
double heightValue = 0;

// I have no idea wtf is this
double mathResult = 0;

// Used for bmi calculation, and to convert units to metric-european if necessary.
double bmiWeight = 0;
double bmiHeight = 0;

//------------------------------------------------------------------------------------
// Functioning code

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


// ----------- // QMenu signals


void MainWindow::on_inputWeight_valueChanged(double arg1)
{
    weightValue = arg1;
    bmiCalculator();
}

void MainWindow::on_inputHeight_valueChanged(double arg1)
{
    heightValue = arg1;
    bmiCalculator();
}

void MainWindow::on_inputAge_valueChanged(int arg1)
{
    ageValue = arg1;
    bmiCalculator();
}



// ----------- UI Modifying Functions


void MainWindow::spinBoxProperties(QString boxName, double singleStepVal, int decimalsVal) {

    // Changing a QDoubleSpinBox values
    MainWindow::findChild<QDoubleSpinBox*>(boxName)->setSingleStep(singleStepVal);
    MainWindow::findChild<QDoubleSpinBox*>(boxName)->setDecimals(decimalsVal);
}

// Updating value of spinBox after conversion.
    void MainWindow::setValueBox(QString boxName, double value) {
    MainWindow::findChild<QDoubleSpinBox*>(boxName)->setValue(value);
}

// ---- UI Signals Functions

void MainWindow::on_weightKG_clicked()
{
    // change singleStep and decimals on UI.


    // if radio was set on feet, then convert weightInput.
    // if radio was already set on KG, then do nothing.
    if (weightLog != "KG") {

        // Converting from Pound to KG
        weightValue = valueConverter(weightValue, 2.205, '/');

        // Updating value on UI element
        setValueBox("inputWeight", weightValue);

        weightLog = "KG";
        // Changing weight spinbox wheel properties
        spinBoxProperties("inputWeight", 5, 1);
        bmiCalculator();

    }
}

void MainWindow::on_weightPounds_clicked()
{
    // change singleStep and decimals on UI.


    // if radio was set on pounds, then convert weightInput.
    // if radio was already set on KG, then do nothing.
    if (weightLog != "pounds") {

        // Converting from Pound to KG
        weightValue = valueConverter(weightValue, 2.205, '*');

        // Updating value on UI element
        weightLog = "pounds";
        // Changing weight spinbox wheel properties
        setValueBox("inputWeight", weightValue);
        spinBoxProperties("inputWeight", 10, 2);
        bmiCalculator();


    }
}

void MainWindow::on_heightM_clicked()
{

    // if radio was set on feet then convert weightInput, otherwise do nothing.

    if (heightLog != "M") {

        // Converting from feet to meter
        heightValue = valueConverter(heightValue, 3.281, '/');
        heightLog = "M";




        // Changing weight spinbox wheel properties
        spinBoxProperties("inputHeight", 0.15, 2);
        // Updating value on UI element
        setValueBox("inputHeight", heightValue);
        bmiCalculator();

    }
}


void MainWindow::on_heightFeet_clicked()
{
    // if radio was set on feet then convert weightInput, otherwise do nothing.

    if (heightLog != "feet") {

        // Converting from M to feet
        heightValue = valueConverter(heightValue, 3.281, '*');
        heightLog = "feet";

        // Changing weight spinbox wheel properties
        spinBoxProperties("inputHeight", 0.5, 2);

        // Updating value on UI element
        setValueBox("inputHeight", heightValue);


        bmiCalculator();


    }
}




// -----   Math Logic functions

double MainWindow::valueConverter(double valueInput, double valueCalculator, char mathOperator) {


    if (mathOperator == '*') {
        mathResult = valueInput * valueCalculator;
    }

    else {
        mathResult = valueInput / valueCalculator;
    }

    return mathResult;
}

bool MainWindow::valuesChecker(double value) {
    if (value != 0) {
        return true;
    }

    else {
        return false;
    }
}

bool MainWindow::valuesChecker(int value){
    // Used for age
    if (value != 0) {
        return true;
    }

    else {
        return false;
    }
}

void MainWindow::bmiCalculator() {


    // Check that all values are different from 0. To avoid a calculation error.
    if (valuesChecker(ageValue) == true && valuesChecker(weightValue) == true && valuesChecker(heightValue) == true) {

        // Check that all measures are metrical. If they are not, convert them and update the history log.
        if (weightLog != "KG") {
            bmiWeight = ui->inputWeight->value();
            bmiWeight = MainWindow::valueConverter(bmiWeight, 2.205, '/');
        }
        else {
            bmiWeight = weightValue;
        }
        // debug feedback
        qDebug() << "\n" << "weightLog: " << QString::fromStdString(weightLog);
        qDebug() << "bmiWeight value: " << bmiWeight;


        // Checking if height is in meters or feet
        if (heightLog != "M") {
            bmiHeight = ui->inputHeight->value();
            bmiHeight = MainWindow::valueConverter(heightValue, 3.281, '/');
        }
        else {
            bmiHeight = heightValue;
        }
        // debug feedback
        qDebug() << "heightLog: " << QString::fromStdString(heightLog);
        qDebug() << "bmiHeight value after conversion: " << bmiHeight;


        // Calculate BMI using metrical units
        double bmiResult = bmiWeight / (bmiHeight * bmiHeight);
        // Print result on UI label, truncating to only two decimal values.
        ui->bmiResult->setText(QString::number(bmiResult, 10, 2));
    }

}










