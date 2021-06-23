#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton* button;
    QCheckBox* checkbox;
    QVBoxLayout *layout;
    QWidget* window;

};

#endif
