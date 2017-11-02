#include <QCoreApplication>
#include "singleinstance.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "com.company.application";

    SingleInstance cInstance;
    if(cInstance.hasPrevious(name, QCoreApplication::arguments()))
    {
        qDebug() << "Previous instance detected!";
        return 0;
    }


    qDebug() << "There can be only one!";
    cInstance.listen(name);

    return a.exec();
}
