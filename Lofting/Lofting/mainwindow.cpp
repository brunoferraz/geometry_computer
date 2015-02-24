#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGLWidget>
#include <QDebug>
#include <interface.h>
#include <QButtonGroup>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonGroupBasic.addButton(ui->pushButton);
    buttonGroupBasic.addButton(ui->pushButton_2);
    buttonGroupBasic.addButton(ui->pushButton_3);
    buttonGroupBasic.addButton(ui->pushButton_4);
    buttonGroupBasic.addButton(ui->pushButton_5);
    buttonGroupBasic.addButton(ui->pushButton_6);
    connect(&buttonGroupBasic,SIGNAL(buttonClicked(int)),SLOT(basicButtonClicked(int)));

    Interface::ui = ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    Keyboard::keyPress(ev);
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    Keyboard::keyRelease(ev);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0) {
        Interface::tool.setTool(Tool::TRANSLATE);
    }else if(index == 1){
        Interface::tool.setTool(Tool::LOFT);
    }
}

void MainWindow::basicButtonClicked(int index)
{
    switch(std::abs(index)){
    case 2:
        Interface::tool.setTool(Tool::SELECT);
    break;
    case 3:
        Interface::tool.setTool(Tool::CAMERA);
    break;
    case 4:
        Interface::tool.setTool(Tool::DRAW);
    break;
    case 5:
        Interface::tool.setTool(Tool::TRANSLATE);
    break;
    case 6:
        Interface::tool.setTool(Tool::ROTATE);
    break;
//    case 7:
//        Interface::tool.setTool(Tool::SCALE);
//    break;
    case 8:
        Interface::tool.setTool(Tool::LOFT);
        break;
    default:
        qDebug() << "need to implement";
        break;
    }
}
