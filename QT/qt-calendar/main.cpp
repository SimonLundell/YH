#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow* window = new MainWindow();
    window->show();


    return app.exec();
}