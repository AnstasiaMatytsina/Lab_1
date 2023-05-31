#include "filechecker.h"
#include <consoleprinter.h>
#include <iostream>

using namespace std;

FileChecker* FileChecker:: Instance(){
    static FileChecker instance;
    return &instance;
}

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

void FileChecker::checkSizeByPosition(int position) {
    State savedState = save[position];
    State newState(savedState.getPath());
    if (savedState.getSize()!=newState.getSize()) {
        sizeSignal(newState.getPath(), newState.getSize());
        changeStateByPosition(newState, position);
    }
}

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

void FileChecker::remove(int position) {
    save.remove(position);
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
