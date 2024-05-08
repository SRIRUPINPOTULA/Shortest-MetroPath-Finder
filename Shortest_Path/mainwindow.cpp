#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include<graph.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString userInput = ui->lineEdit->text();
    QMessageBox::information(this, "User Input", "You entered: " + userInput);
}


void MainWindow::on_lineEdit_2_returnPressed()
{
    QString userInput = ui->lineEdit->text();
    QMessageBox::information(this, "User Input", "You entered: " + userInput);
}


void MainWindow::on_pushButton_pressed()
{
    QString sourceText = ui->lineEdit->text();
    QString destText = ui->lineEdit_2->text();
    QString method = ui->comboBox->currentText(); // Use currentText() to get the currently selected item's text

    if (method=="Purple Line Stations"){
        QString purpleStations = QString::fromStdString(graph.getPurpleStationsString());
        QMessageBox::information(this, "Purple Line Stations", purpleStations);
        //QLabel *label = new QLabel(purpleStations);
        // Enable word wrap to ensure all stations are visible
        //label->setWordWrap(true);

        // Create a scroll area and set the QLabel as its widget
        //QScrollArea *scrollArea = new QScrollArea;
        //scrollArea->setWidget(label);

        // Set the scroll area as the central widget of the main window
        //setCentralWidget(scrollArea);
    }

    else if(method=="Green Line Stations")
    {
        QString greenStations = QString::fromStdString(graph.getGreenStationsString());
        QMessageBox::information(this, "Purple Line Stations", greenStations);
        //QLabel *label = new QLabel(greenStations);
        // Enable word wrap to ensure all stations are visible
        //label->setWordWrap(true);

        // Create a scroll area and set the QLabel as its widget
        //QScrollArea *scrollArea = new QScrollArea;
        //scrollArea->setWidget(label);

        // Set the scroll area as the central widget of the main window
        //setCentralWidget(scrollArea);
    }
    else if(method=="Breadth First Search")
    {
        QString pathFound = QString::fromStdString(graph.findPath(sourceText.toStdString(), destText.toStdString()));
        QMessageBox::information(this, "Path Found", pathFound);
    }

    else if(method=="Djikstra's Algorithm")
    {
        QString pathFound = QString::fromStdString(graph.djikstra(sourceText.toStdString(), destText.toStdString()));
        QMessageBox::information(this, "Path Found", pathFound);
    }
    else if (method == "All Stations") {
        QString allStations = QString::fromStdString(graph.getPurpleStationsString() + "\n" + graph.getGreenStationsString());
        QMessageBox::information(this, "All Stations", allStations);
    }

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Breadth First Search") {
        // Perform actions specific to BFS
        QMessageBox::information(this, "Algorithm Selected", "BFS (Breadth-First Search) selected.");
    } else if (arg1 == "Djikstra's Algorithm") {
        // Perform actions specific to Djikstra's Algorithm
        QMessageBox::information(this, "Algorithm Selected", "Djikstra's Algorithm selected.");
    }
}



