#include "state.h"

State::State(const QString &filePath) {
    QFileInfo info(filePath);
    path=info.absoluteFilePath();
    exist=info.exists();
    size=info.size();
}

QString State::getPath(){
    return path;
}

bool State::getExist(){
    return exist;
}

qint64 State::getSize(){
    return size;
}
