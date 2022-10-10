/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: SqQueue.h
 * @filepath: head\SqQueue.h
 * @date: 2022-10-10 13:36:13
 * @description: 循环队列
 */

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__

template <class T> class SqQueue {
  private:
    T *data;
    int front;
    int rear;
    int maxSize;

  public:
    SqQueue(int maxSize = 0);
    ~SqQueue();
    bool isEmpty();
    bool isFull();
    int getLength();
    T getFront();
    T getRear();
    bool EnQueue(T x);
    bool DeQueue(T &x);
    void print();
    void clear();
};
template <class T>
SqQueue<T>::SqQueue(int maxSize) : maxSize(maxSize), front(0), rear(0) {
    data = new T[maxSize];
}

template <class T> SqQueue<T>::~SqQueue() { delete (data); }

template <class T> bool SqQueue<T>::isEmpty() {
    if (front == rear)
        return true;
    else
        return false;
}

template <class T> bool SqQueue<T>::isFull() {
    if ((rear + 1) % maxSize == front)
        return true;
    else
        return false;
}

template <class T> int SqQueue<T>::getLength() {
    return (rear - front + maxSize) % maxSize;
}

template <class T> T SqQueue<T>::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    return data[front];
}

template <class T> T SqQueue<T>::getRear() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    return data[(rear - 1 + maxSize) % maxSize];
}

template <class T> bool SqQueue<T>::EnQueue(T x) {
    if (isFull()) {
        cout << "Queue is Full" << endl;
        return false;
    }
    data[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

template <class T> bool SqQueue<T>::DeQueue(T &x) {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return false;
    }
    front = (front + 1) % maxSize;
}

template <class T> void SqQueue<T>::print() {
    for (int i = front; i != rear; i = (i + 1) % maxSize) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T> void SqQueue<T>::clear() { front = rear = 0; }

#endif
