#include <QCoreApplication>
#include <filechecker.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileChecker t;
    t.add("D:/1.txt");
    while(1) {
        t.check();
    }
    return a.exec();
}
