#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
#include <cmath>
#include <csv.hpp>
#include <QDesktopServices>

// Links from clickable buttons
QString homepage = "https://github.com/dariopedroniDEV/BMIcalculator";
QString donatePage = "https://dariopedroni.dev/donate/";

// QMenu signals



// BMI data taken from
// https://www.calculator.net/bmi-calculator.html

// Declaring variables. QPair holding user input but that can easily be changed.
int ageValue = 0;
double weightValue = 0;
double heightValue = 0;
double mathResult = 0;

std::string weightLog = "KG";
std::string heightLog= "M";

//------------------------------------------------------------------------------------
// Functioning code

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
ui->setupUi(this);
// Initializing QVectors with placeholder data, that will afterwards be assigned user-inputs.

}


// Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputWeight_valueChanged(double arg1)
{
    weightValue = arg1;
}

void MainWindow::on_inputHeight_valueChanged(double arg1)
{
    heightValue = arg1;
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


    }
}


// Math Logic functions

double MainWindow::valueConverter(double valueInput, double valueCalculator, char mathOperator) {


    if (mathOperator == '*') {
        mathResult = valueInput * valueCalculator;
    }

    else {
        mathResult = valueInput / valueCalculator;
    }

    return mathResult;
}








void MainWindow::on_heightM_clicked()
{



    // if radio was set on feet then convert weightInput, otherwise do nothing.

    if (heightLog != "M") {

        // Converting from M to Feet
        heightValue = valueConverter(heightValue, 3.281, '*');

        // Updating value on UI element
        setValueBox("inputHeight", heightValue);

        weightLog = "M";
        // Changing weight spinbox wheel properties
        spinBoxProperties("inputHeight", 0.15, 2);

    }
}


void MainWindow::on_heightFeet_clicked()
{
    // if radio was set on feet then convert weightInput, otherwise do nothing.

    if (heightLog != "feet") {

        // Converting from Feet to M
        heightValue = valueConverter(heightValue, 3.281, '/');

        // Updating value on UI element
        setValueBox("inputHeight", heightValue);

        weightLog = "feet";
        // Changing weight spinbox wheel properties
        spinBoxProperties("inputHeight", 0.5, 2);

    }
}




