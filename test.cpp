#include "DS_WK/CustomException.h"

#include <cstddef>
#include <iostream>
using namespace std;

class SqList {
  private:
    int *data;
    int length;

  public:
    SqList();
    SqList(int length);
    SqList(const SqList &other);
    ~SqList();

    int getLength() const;
    int getData(int index) const;
    void setData(int x, int index);
    void print();
    void print(int low, int high);
};

SqList::SqList() : length(0), data(NULL) {}

SqList::SqList(int length) : length(length), data(new int[length]) {}

SqList::SqList(const SqList &other) {
    cout << "¿½±´¹¹Ôìº¯Êý" << endl;
    length = other.getLength();
    data = new int[length];
    for (int i = 0; i < length; i++) {
        data[i] = other.getData(i);
    }
}

int SqList::getLength() const { return length; }

int SqList::getData(int index) const {
    if (length == 0) {
        throw OutOfRange();
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index);
    }
    return data[index];
}

void SqList::setData(int x, int index) {
    if (length == 0) {
        throw OutOfRange();
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index);
    }
    data[index] = x;
}

void SqList::print() {
    if (length == 0) {
        throw OutOfRange();
    }
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void SqList::print(int low, int high) {
    if (length == 0) {
        throw OutOfRange();
    } else if (low < 0 || high >= length || low > high) {
        throw OutOfRange(length, low, high);
    }
    for (int i = low; i <= high; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

SqList::~SqList() {
    delete (data);
    cout << "~SqList: delete success!" << endl;
}


int main() {
    SqList sqlist(10);
    for(int i=0; i<10; i++) {
        sqlist.setData(i, i);
    }   
    sqlist.print();


    return 0;
}