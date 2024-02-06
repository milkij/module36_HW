#include "myWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyWidget *newWidjet = new MyWidget(nullptr);
    newWidjet->setFixedSize(300,250);
    newWidjet->move(1000,500);
    newWidjet->show();

    return QApplication::exec();
}
