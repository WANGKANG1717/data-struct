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

    //检查越界
    inline void checkRange() const;
    inline void checkRange(int index) const;
    inline void checkRange(int low, int high) const;
    //比较函数 默认比较器
    //本来想默认一个存储器的，结果失败了
    //还是暂时放弃
    inline bool cmp(const T a, const T b);

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
    void _delete(int index); // 删除
    void bubbleSort(int low, int high,
                    bool (*func)(T, T)); //升序排序 第三个参数是比较参数
    //返回下标
    int binarySearch(int low, int high, T x); //二分查找
    int search(int low, int high, T x);       //顺序查找
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

template <class T> inline void SqList<T>::checkRange() const {
    if (length == 0) {
        throw OutOfRange();
    }
}

template <class T> inline void SqList<T>::checkRange(int index) const {
    if (length == 0) {
        throw OutOfRange();
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index);
    }
}

template <class T> inline void SqList<T>::checkRange(int low, int high) const {
    if (length == 0) {
        throw OutOfRange();
    } else if (low < 0 || high >= length || low > high) {
        throw OutOfRange(length, low, high);
    }
}

template <class T> inline bool SqList<T>::cmp(T a, T b) {
    return a<b;
}

template <class T> int SqList<T>::getLength() const { return length; }

template <class T> T SqList<T>::getData(int index) const {
    checkRange(index);
    return data[index];
}

template <class T> void SqList<T>::setData(T x, int index) {
    checkRange(index);
    data[index] = x;
}

template <class T> void SqList<T>::print() const {
    checkRange();
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T> void SqList<T>::print(int low, int high) const {
    checkRange(low, high);
    for (int i = low; i <= high; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T> void SqList<T>::insert(int index, T x) {
    checkRange(index);
    cout << "insert!" << endl;
    for (int i = length - 1; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = x;
}

template <class T> void SqList<T>::_delete(int index) {
    checkRange(index);
    cout << "delete!" << endl;
    for (int i = index; i <length-1; i++) {
        data[i] = data[i + 1];
    }
}

template <class T>
void SqList<T>::bubbleSort(int low, int high, bool (*func)(T, T))  {
    checkRange(low, high);
    cout << "bubbleSort" << endl;
    for (int i = high; i > low; i--) {
        for (int j = low; j < i; j++) {
            if ((*func)(data[i], data[j])) {
                swap(data[i], data[j]);
            }
        }
    }
}

template <class T> int SqList<T>::binarySearch(int low, int high, T x) {
    checkRange(low, high);
    cout << "binarySearch" << endl;
    while(low<=high) {
        int mid=(low+high)/2;
        if(data[mid]==x) {
            return mid;
        }
        else if(x<data[mid]) {
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}

template <class T> int SqList<T>::search(int low, int high, T x) {
    checkRange(low, high);
    for(int i=low; i<high; i++) {
        if(data[i]==x) {
            return i;
        }
    }
    return -1;
}

template <class T> void SqList<T>::reverse(int low, int high) {
    checkRange(low, high);
    while(low<high) {
        swap(data[low], data[high]);
        low++;
        high--;
    }
}

#endif