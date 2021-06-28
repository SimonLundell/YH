#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    window = new QWidget(this);
    this->setFixedWidth(680);
    this->setFixedHeight(420);
    window->resize(width(), height());

    layout = new QGridLayout();

    calendar = new QCalendarWidget();
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);

    layout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    window->setLayout(layout);
}

MainWindow::~MainWindow(){
}
