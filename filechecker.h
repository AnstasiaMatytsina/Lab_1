#ifndef FILECHEKER_H
#define FILECHEKER_H
#include <QVector>
#include<state.h>
#include <QObject>

class FileChecker: public QObject
{
    Q_OBJECT
private:
    QVector<State> save;//вектор, который хранит состояния файла
    void changeStateByPosition(const State &newState, int position);
    void checkExistByPosition(int position);
    void checkExist();
    void checkSizeByPosition(int position);
    void checkSize();
public:
    FileChecker();
    void add(const QString &filePath);
    bool remove(const QString &filePath);
    void check();
//сигналы
signals:
    void existSignal(const QString& path, bool existence);
    void sizeSignal(const QString& path, qint64 size);
};


#endif // FILECHEKER_H

