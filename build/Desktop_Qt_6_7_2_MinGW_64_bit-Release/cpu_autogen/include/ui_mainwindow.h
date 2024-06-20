/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_numProcesses;
    QLineEdit *lineEdit_numProcesses;
    QLabel *label_algorithm;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QLabel *label_quantum;
    QLineEdit *lineEdit_quantum;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 471);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        label_numProcesses = new QLabel(centralWidget);
        label_numProcesses->setObjectName("label_numProcesses");

        verticalLayout->addWidget(label_numProcesses);

        lineEdit_numProcesses = new QLineEdit(centralWidget);
        lineEdit_numProcesses->setObjectName("lineEdit_numProcesses");

        verticalLayout->addWidget(lineEdit_numProcesses);

        label_algorithm = new QLabel(centralWidget);
        label_algorithm->setObjectName("label_algorithm");

        verticalLayout->addWidget(label_algorithm);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 27)
            tableWidget->setRowCount(27);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        label_quantum = new QLabel(centralWidget);
        label_quantum->setObjectName("label_quantum");

        verticalLayout->addWidget(label_quantum);

        lineEdit_quantum = new QLineEdit(centralWidget);
        lineEdit_quantum->setObjectName("lineEdit_quantum");

        verticalLayout->addWidget(lineEdit_quantum);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Scheduling Algorithms", nullptr));
        label_numProcesses->setText(QCoreApplication::translate("MainWindow", "Enter Number of Processes:", nullptr));
        label_algorithm->setText(QCoreApplication::translate("MainWindow", "Choose Scheduling Algorithm:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Burst Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "SJF", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Priority", nullptr));

        label_quantum->setText(QCoreApplication::translate("MainWindow", "Enter Quantum Time for Round Robin:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
