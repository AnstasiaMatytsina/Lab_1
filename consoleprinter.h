#ifndef CONSOLEPRINTER_H
#define CONSOLEPRINTER_H
#include <QObject>

class ConsolePrinter : public QObject
{
public slots:
    static void printerByExist(const QString& path, bool existence);
    static void printerBySize(const QString& path, qint64 size);
};

#endif // CONSOLEPRINTER_H
