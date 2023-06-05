#include "filechecker.h"
#include <consoleprinter.h>
#include <iostream>

using namespace std;

void FileChecker::changeStateByPosition(const State &newState, int position) {
    save[position] = newState;
}

void FileChecker::checkExistByPosition(int position) {
    State savedState = save[position];
    State newState(savedState.getPath());
    if (savedState.getExist()!=newState.getExist()) {
        existSignal(newState.getPath(), newState.getExist());
        changeStateByPosition(newState, position);
    }
}
//Сравниваем старое состояние с текущим, если изменения есть подаем сигнал и меняем состояние в векторе
void FileChecker::checkSizeByPosition(int position) {
    State savedState = save[position];
    State newState(savedState.getPath());
    if (savedState.getSize()!=newState.getSize()) {
        sizeSignal(newState.getPath(), newState.getSize());
        changeStateByPosition(newState, position);
    }
}
//Идем по фектору и вызываем функцию для проверки изменений
void FileChecker::checkSize() {
    for(int pos = 0; pos < save.count(); pos++) {
        checkSizeByPosition(pos);
    }
}

FileChecker::FileChecker()
{
    connect(this, &FileChecker::existSignal, &ConsolePrinter::printerByExist);
    connect(this, &FileChecker::sizeSignal, &ConsolePrinter::printerBySize);
}

void FileChecker::add(const QString &filePath) {
    State newState(filePath);
    save.push_back(newState);
}

bool FileChecker::remove(const QString &filePath) {
    State remstate(filePath);
    if(save.contains(remstate) ){
        save.removeOne(remstate);
        return true;
    }
    else return false;
}

void FileChecker::check() {
    checkExist();
    checkSize();
}

void FileChecker::checkExist() {
    for(int pos = 0; pos < save.count(); pos++) {
        checkExistByPosition(pos);
    }
}

