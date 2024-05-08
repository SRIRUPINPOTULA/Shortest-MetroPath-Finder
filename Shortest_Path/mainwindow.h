#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "graph.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_pressed();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Graph graph;
};
#endif // MAINWINDOW_H
