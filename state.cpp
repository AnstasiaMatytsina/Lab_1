#include "state.h"

State::State(const QString &filePath) {
    QFileInfo info(filePath);//вызываем конструктор с параметром
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
bool State::operator==(const State& file)const {   // перегрузка оператора сравнения

    if (file.path == path)
        return true;
    return false;
}
