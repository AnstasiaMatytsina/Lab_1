#include "state.h"

State::State(const QString &filePath) {
    QFileInfo info(filePath);
    path=info.absoluteFilePath();
    size=info.size();
    exist=info.exists();
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
