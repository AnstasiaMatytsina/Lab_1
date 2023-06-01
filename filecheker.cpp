#include "filechecker.h"
#include <consoleprinter.h>
#include <iostream>

using namespace std;

//Подключаем сигналы в слоты
FileChecker::FileChecker()
{
    connect(this, &FileChecker::existSignal, &ConsolePrinter::printerByExist);
    connect(this, &FileChecker::sizeSignal, &ConsolePrinter::printerBySize);
}

void FileChecker::changeStateByPosition(const State &newState, int position) {
    save[position] = newState;
}
//Сравниваем текущее состояние с последним сохраненным
void FileChecker::checkExistByPosition(int position) {
    State savedState = save[position];
    State newState(savedState.getPath());
    if (savedState.getExist()!=newState.getExist()) {
        existSignal(newState.getPath(), newState.getExist());
        changeStateByPosition(newState, position);
    }
}

void FileChecker::checkSizeByPosition(int position) {
    State savedState = save[position];
    State newState(savedState.getPath());
    if (savedState.getSize()!=newState.getSize()) {
        sizeSignal(newState.getPath(), newState.getSize());
        changeStateByPosition(newState, position);
    }
}
//Идем по вектору и вызываем функцию для проверки изменений
void FileChecker::checkSize() {
    for(int pos = 0; pos < save.count(); pos++) {
        checkSizeByPosition(pos);
    }
}

void FileChecker::add(const QString &filePath) {
    State newState(filePath);
    save.push_back(newState);
}

void FileChecker::remove(int position) {
    save.remove(position);
}

void FileChecker::check() {
    checkExist();
    checkSize();
}
//Идем по вектору и вызываем функцию для проверки изменений
void FileChecker::checkExist() {
    for(int pos = 0; pos < save.count(); pos++) {
        checkExistByPosition(pos);
    }
}
