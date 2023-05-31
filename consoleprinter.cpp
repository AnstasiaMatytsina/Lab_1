#include "consoleprinter.h"
#include <iostream>

using namespace std;

void ConsolePrinter::printerByExist(const QString &path, bool existence) {
    wcout << "File" <<  path.toStdWString();
    if (existence) {
        wcout << " - exists" << endl;
    }
    else {
        wcout << " - not exists" << endl;
    }
}

void ConsolePrinter::printerBySize(const QString &path, qint64 size) {
    wcout << "File" <<  path.toStdWString()<< ", size - " << size << endl;
}
