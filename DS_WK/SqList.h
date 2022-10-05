/**
 * @filename: SqList.h
 * @author: WangKang
 * @blog: kang17.xyz
 * @email: 1686617586@qq.com
 * @date: 2022-10-04 18:49:54
 * @description: 顺序表模板类
 */
#include "CustomException.h"

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __SQLIST_H__
#define __SQLIST_H__

template <class T> class SqList {
  private:
    T *data;
    int length;

  public:
    SqList();
    SqList(int length);
    SqList(const SqList<T> &other); //拷贝构造函数
    ~SqList();

    //顺序表的基本操作
    int getLength() const;
    T getData(int index) const;
    void setData(T x, int index);
    void print() const;
    void print(int low, int high) const;
    //
    void insert(int index, T x); //插入
    void sortUP(int low, int high,
                int (*func)(T, T)); //升序排序 第三个参数是比较参数
    void sortDOWN(int low, int high, int (*func)(T, T)); //降序排序
    T binarySearch(int low, int high, T x);              //二分查找
    T search(int low, int high, T x);                    //顺序查找
    void reverse(int low, int high);
};

template <class T> SqList<T>::SqList() : length(0), data(NULL) {}

template <class T>
SqList<T>::SqList(int length) : length(length), data(new T[length]) {}

template <class T> SqList<T>::SqList(const SqList<T> &other) {
    length = other.getLength();
    //我说怎么总是报一些莫名奇妙的错误，原来是申请数组的方法有误
    //受java影响有些深啊
    data = new T[length];
    for (int i = 0; i < length; i++) {
        data[i] = other.getData(i);
    }
}

template <class T> SqList<T>::~SqList() {
    delete (data);
    cout << "~SqList: delete success!" << endl;
}

template <class T> int SqList<T>::getLength() const { return length; }

template <class T> T SqList<T>::getData(int index) const {
    if (length == 0) {
        throw OutOfRange();
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index);
    }
    return data[index];
}

template <class T> void SqList<T>::setData(T x, int index) {
    if (length == 0) {
        throw OutOfRange();
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index);
    }
    data[index] = x;
}

template <class T> void SqList<T>::print() const {
    if (length == 0) {
        throw OutOfRange();
    }
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T> void SqList<T>::print(int low, int high) const {
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

template <class T> void SqList<T>::insert(int index, T x) {}

template <class T>
void SqList<T>::sortUP(int low, int high, int (*func)(T, T)) {}

template <class T>
void SqList<T>::sortDOWN(int low, int high, int (*func)(T, T)) {}

template <class T> T SqList<T>::binarySearch(int low, int high, T x) {}

template <class T> T SqList<T>::search(int low, int high, T x) {}

template <class T> void SqList<T>::reverse(int low, int high) {}

#endif