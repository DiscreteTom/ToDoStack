#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStack>
#include <QString>
#include <QTableWidget>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //data
    //QStack<QString> stack;

    //ui
    QLineEdit * newEventLe;
    QPushButton * pushBtn;
    QPushButton * popBtn;

    QTableWidget * eventTable;

    //save & load
    void save();
    void load();

    //table function
    void eventPush(const QString & name);
    void eventPop();

private slots:
    void getPush();
    void getPop();

protected:
    void keyPressEvent(QKeyEvent * e);
};

#endif // MAINWINDOW_H
