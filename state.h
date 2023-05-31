#ifndef STATE_H
#define STATE_H

#include <QFileInfo>

class State
{
private:
    qint64 size;
    QString path;
    bool exist;
public:
    State(const QString &filePath);
    QString getPath();
    bool getExist();
    qint64 getSize();
};


#endif // STATE_H
