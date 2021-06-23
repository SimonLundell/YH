#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    window = new QWidget(this);
    window->resize(width(), height());

    layout = new QVBoxLayout(window);
    button = new QPushButton("Click me");
    checkbox = new QCheckBox("Agree");

    layout->addWidget(button);
    layout->addWidget(checkbox);

    window->setLayout(layout);
}

MainWindow::~MainWindow(){
}
