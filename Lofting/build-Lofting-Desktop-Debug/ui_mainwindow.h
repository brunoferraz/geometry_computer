/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "glcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    GLcanvas *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *tab_2;
    QPushButton *Loft_ShapePick;
    QPushButton *Loft_PathPick;
    QPushButton *Loft_apply;
    QPushButton *pushButton_10;
    QCheckBox *checkBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(567, 299);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new GLcanvas(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 281));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(400, 10, 161, 281));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 70, 141, 27));
        pushButton_3->setCheckable(true);
        pushButton_3->setChecked(true);
        pushButton_3->setAutoExclusive(true);
        pushButton_3->setFlat(false);
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 40, 141, 27));
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoExclusive(true);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 141, 27));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setAutoExclusive(true);
        pushButton->setFlat(false);
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 150, 141, 27));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoExclusive(true);
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 180, 141, 27));
        pushButton_5->setCheckable(true);
        pushButton_5->setAutoExclusive(true);
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 210, 141, 27));
        pushButton_6->setCheckable(true);
        pushButton_6->setAutoExclusive(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Loft_ShapePick = new QPushButton(tab_2);
        Loft_ShapePick->setObjectName(QStringLiteral("Loft_ShapePick"));
        Loft_ShapePick->setGeometry(QRect(10, 10, 141, 27));
        Loft_ShapePick->setCheckable(true);
        Loft_ShapePick->setAutoExclusive(true);
        Loft_PathPick = new QPushButton(tab_2);
        Loft_PathPick->setObjectName(QStringLiteral("Loft_PathPick"));
        Loft_PathPick->setGeometry(QRect(10, 40, 141, 27));
        Loft_PathPick->setCheckable(true);
        Loft_PathPick->setAutoExclusive(true);
        Loft_apply = new QPushButton(tab_2);
        Loft_apply->setObjectName(QStringLiteral("Loft_apply"));
        Loft_apply->setGeometry(QRect(10, 180, 141, 27));
        Loft_apply->setCheckable(false);
        Loft_apply->setAutoExclusive(false);
        pushButton_10 = new QPushButton(tab_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 210, 141, 27));
        pushButton_10->setCheckable(false);
        pushButton_10->setAutoExclusive(false);
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 70, 121, 22));
        checkBox->setChecked(true);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Draw", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Camera", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Select", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Translate", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Rotate", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Scale", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Basic", 0));
        Loft_ShapePick->setText(QApplication::translate("MainWindow", "Pick Shapes", 0));
        Loft_PathPick->setText(QApplication::translate("MainWindow", "Pick Path", 0));
        Loft_apply->setText(QApplication::translate("MainWindow", "Apply", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Save", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Debug Mode", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Loft", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
