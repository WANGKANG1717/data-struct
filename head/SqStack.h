/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: SqStack.h
 * @date: 2022-10-09 13:02:26
 * @description: 堆栈，顺序存储实现
 */

/**
 * @date: 2022-10-09 14:17:12
 * @description: 本来想用vscode的代码片段是实现自动的文件名的转换的
 *               结果翻车了，找了一个小时，没解决这个问题！
 */

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __STACK_H__
#define __STACK_H__
template <class T> class SqStack {
  private:
    int maxSize;
    T *data;
    int top;

  public:
    SqStack(int maxSize = 0);
    ~SqStack();
    bool isEmpty();
    bool isFull();
    void clear();
    int getLength();
    bool push(T x);
    T pop();
    T getTop();
};
template <class T> SqStack<T>::SqStack(int maxSize) : maxSize(maxSize), top(0) {
    data = new T[maxSize];
}

template <class T> SqStack<T>::~SqStack() { delete (data); }

template <class T> bool SqStack<T>::isEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}

template <class T> bool SqStack<T>::isFull() {
    if (top == maxSize)
        return true;
    else
        return false;
}

template <class T> void SqStack<T>::clear() { top = 0; }

template <class T> int SqStack<T>::getLength() { return top; }

template <class T> bool SqStack<T>::push(T x) {
    if (isFull()) {
        cout << "SqStack is full!" << endl;
        return false;
    }
    data[top++] = x;
    return true;
}

template <class T> T SqStack<T>::pop() {
    if (isEmpty()) {
        cout << "SqStack is empty!" << endl;
        return NULL;
    }
    return data[--top];
}

template <class T> T SqStack<T>::getTop() {
    if (isEmpty()) {
        cout << "statck is Empty!" << endl;
        return 0;
    }
    return data[top - 1];
}

#endif