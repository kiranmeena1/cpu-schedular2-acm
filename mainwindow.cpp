// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <vector>
#include <algorithm>
using namespace std;

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

void MainWindow::on_pushButton_clicked()
{
    int n = ui->lineEdit_numProcesses->text().toInt();
    Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = ui->tableWidget->item(i, 0)->text().toInt();
        proc[i].arrivalTime = ui->tableWidget->item(i, 1)->text().toInt();
        proc[i].burstTime = ui->tableWidget->item(i, 2)->text().toInt();
        proc[i].priority = ui->tableWidget->item(i, 3)->text().toInt();
    }

    int choice = ui->comboBox->currentIndex();
    int quantum = 0;
    if (choice == 3) {
        quantum = ui->lineEdit_quantum->text().toInt();
    }

    switch (choice) {
    case 0:
        findFCFS(proc, n);
        break;
    case 1:
        findSJF(proc, n);
        break;
    case 2:
        findRoundRobin(proc, n, quantum);
        break;
    case 3:
        findPriority(proc, n);
        break;
    default:
        QMessageBox::warning(this, "Error", "Invalid choice!");
        return;
    }

    displayProcessDetails(proc, n);
    displayGanttChart(proc, n);
}

void MainWindow::findFCFS(Process proc[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < proc[i].arrivalTime) {
            currentTime = proc[i].arrivalTime;
        }
        proc[i].waitingTime = currentTime - proc[i].arrivalTime;
        currentTime += proc[i].burstTime;
        proc[i].completionTime = currentTime;
        proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
    }
}

void MainWindow::findSJF(Process proc[], int n) {
    vector<Process> processes(proc, proc + n);
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.burstTime < b.burstTime;
    });

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    }
    for (int i = 0; i < n; i++) {
        proc[i] = processes[i];
    }
}

void MainWindow::findPriority(Process proc[], int n) {
    vector<Process> processes(proc, proc + n);
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.priority < b.priority;
    });

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    }
    for (int i = 0; i < n; i++) {
        proc[i] = processes[i];
    }
}

void MainWindow::findRoundRobin(Process proc[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].burstTime;
    }

    int currentTime = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = false;
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    proc[i].completionTime = currentTime;
                    proc[i].waitingTime = currentTime - proc[i].burstTime - proc[i].arrivalTime;
                    proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
                    remainingTime[i] = 0;
                }
            }
        }
    } while (!done);
}

void MainWindow::displayProcessDetails(Process proc[], int n) {
    QString result;
    result.append("Process\tArrivalTime\tBurstTime\tWaitingTime\tCompletionTime\tTurnaroundTime\n");
    for (int i = 0; i < n; i++) {
        result.append(QString::number(proc[i].pid) + "\t" +
                      QString::number(proc[i].arrivalTime) + "\t" +
                      QString::number(proc[i].burstTime) + "\t" +
                      QString::number(proc[i].waitingTime) + "\t" +
                      QString::number(proc[i].completionTime) + "\t" +
                      QString::number(proc[i].turnaroundTime) + "\n");
    }
    ui->textEdit->setText(result);
}

void MainWindow::displayGanttChart(Process proc[], int n) {
    QString gantt;
    for (int i = 0; i < n; i++) {
        gantt.append("|  P" + QString::number(proc[i].pid) + "  ");
    }
    gantt.append("|\n");

    gantt.append("  ");
    for (int i = 0; i < n; i++) {
        gantt.append(QString::number(proc[i].completionTime) + "\t");
    }
    ui->textEdit->append(gantt);
}
