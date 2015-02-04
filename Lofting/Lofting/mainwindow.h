#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <Io/keyboard.h>
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    QButtonGroup buttonGroupBasic;

private slots:
    void on_tabWidget_currentChanged(int index);
    void basicButtonClicked(int i);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
