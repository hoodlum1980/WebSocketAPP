#include <iostream>
#include <stdio.h>

#include <QtCore>
#include <QCoreApplication>

#include <infothread.h>
#include <messageserver.h>



int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    messageServer ms;
    ms.runServer();

    return a.exec();
}
