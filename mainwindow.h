// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int completionTime;
    int turnaroundTime;
    int priority;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void findFCFS(Process proc[], int n);
    void findSJF(Process proc[], int n);
    void findPriority(Process proc[], int n);
    void findRoundRobin(Process proc[], int n, int quantum);
    void displayProcessDetails(Process proc[], int n);
    void displayGanttChart(Process proc[], int n);
};

#endif // MAINWINDOW_H
