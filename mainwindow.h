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
#include <QCloseEvent>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include "funcbtn.h"
#include <QList>

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

    //================= private variable ================
    //----------------- window object --------------
    QLineEdit * newEventLe;
    QPushButton * pushBtn;
    QPushButton * popBtn;
    QList<funcBtn *> upBtnList;
    QList<funcBtn *> deleteBtnList;
    QTableWidget * eventTable;

    //----------------- menu in tray ---------------
    QSystemTrayIcon * icon;
    QAction * actionShow;
    QAction * actionClose;
    QAction * actionChangeMinimize;
    QAction * actionChangeWindowOnTop;
    QMenu * menu;

    //------------------- config --------------------
    bool windowOnTop;
    bool minimizeToTray;
    int windowHeight;
    int windowWidth;

    //================= private methods ========================
    //-------------------- about file ------------------
    void save();
    void load();
    void getConfig();
    void setConfig();

    //------------------- about table ----------------------
    void eventPush(const QString & name);
    void eventPop();

private slots:
    void getPush();
    void getPop();
    void trayClicked(QSystemTrayIcon::ActivationReason reason);
    void getShow();
    void getClose();
    void upEvent(int index);
    void deleteEvent(int index);

    void changeMinimize();
    void changeWindowOnTop();

    //to save when table date changed
    void getItemChanged(QTableWidgetItem * item);

protected:
    void keyPressEvent(QKeyEvent * e);
    void closeEvent(QCloseEvent * e);
};

#endif // MAINWINDOW_H
