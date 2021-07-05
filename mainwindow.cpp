#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
// BMI data taken from
// https://www.calculator.net/bmi-calculator.html?ctype=metric&cage=25&csex=m&cheightfeet=5&cheightinch=10&cpound=160&cheightmeter=180&ckg=65&printit=0


// Unused code
/*

*/



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    initializeVector






ui->setupUi(this);
connect(ui->chkState, SIGNAL(clicked()), this, SLOT(object->chkState();));
    }




MainWindow::~MainWindow()
{
    delete ui;
}


void bmiCalculator() {

}

void MainWindow::on_weightInput_valueChanged(const QString &arg1)
{

    bmiCalculator();
}

