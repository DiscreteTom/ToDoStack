#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    newEventLe = new QLineEdit(this);
    pushBtn = new QPushButton(this);
    popBtn = new QPushButton(this);
    pushBtn->setText(tr("Push"));
    popBtn->setText(tr("Pop"));
    eventTable = new QTableWidget(0, 1, this);
    eventTable->setHorizontalHeaderItem(0, NULL);
    eventTable->horizontalHeader()->setStretchLastSection(1);
    eventTable->horizontalHeader()->hide();
    QGridLayout * layout = new QGridLayout(this);
    layout->addWidget(newEventLe, 0, 0, 1, 2);
    layout->addWidget(pushBtn, 1, 0, 1, 1);
    layout->addWidget(popBtn, 1, 1, 1, 1);
    layout->addWidget(eventTable, 2, 0, -1, 2);
    ui->centralWidget->setLayout(layout);

    load();

    connect(pushBtn, &QPushButton::clicked, this, &MainWindow::getPush);
    connect(popBtn, &QPushButton::clicked, this, &MainWindow::getPop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save(){
    QFile file("event");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //QMessageBox::warning(this, tr("保存失败"), tr("无法打开存档文件"));
        return;
    }

    QTextStream out(&file);

    out << eventTable->rowCount() << endl;

    for (int i = 0; i < eventTable->rowCount(); ++i){
        out << eventTable->item(i, 0)->text() << endl;
    }
}


void MainWindow::load(){
    QFile file("event");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        return;
    }

    QTextStream in(&file);

    int n;
    in >> n;

    QStack<QString> stack;

    in.readLine();

    for (int i = 0; i < n; ++i){
        stack.push(in.readLine());
    }
    for (int i = 0; i < n; ++i){
        eventPush(stack.pop());
    }
}

void MainWindow::eventPush(const QString &name)
{
    eventTable->setRowCount(eventTable->rowCount() + 1);
    eventTable->setItem(eventTable->rowCount() - 1, 0, new QTableWidgetItem(tr("")));

    //move item
    for (int i = eventTable->rowCount() - 1; i > 0; --i){
        eventTable->item(i, 0)->setText(eventTable->item(i - 1, 0)->text());
    }

    eventTable->item(0, 0)->setText(name);

    newEventLe->clear();
}

void MainWindow::eventPop()
{
    eventTable->removeRow(0);
}

void MainWindow::getPush()
{
    if (newEventLe->text().length() > 0){
        eventPush(newEventLe->text());
        save();
    }
}

void MainWindow::getPop()
{
    eventPop();
    save();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
    case Qt::Key_Enter:
    case Qt::Key_Return:
        getPush();
        break;
    case Qt::Key_Escape:
        getPop();
        break;
    }
}
