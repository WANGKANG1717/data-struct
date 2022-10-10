/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: LinkQueue.h
 * @filepath: head\LinkQueue.h
 * @date: 2022-10-10 13:58:32
 * @description: 链队
 */

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

template <class T> class QueueNode {
  public:
    T data;
    QueueNode<T> *next;
    QueueNode() : next(NULL){};
    QueueNode(T data, QueueNode<T> *next) : data(data), next(next){};
    ~QueueNode(){};
};

/**
 * @date: 2022-10-10 14:03:56
 * @description: 这次整一个不带头节点的链队
 */
template <class T> class LinkQueue : public QueueNode<T> {
  private:
    QueueNode<T> *front, *rear;

  public:
    LinkQueue();
    ~LinkQueue();

    bool isEmpty();
    int getLength();
    T getFront();
    bool EnQueue(T x);
    bool DeQueue(T &x);
    void print();
    void clear();
};
template <class T> LinkQueue<T>::LinkQueue() : front(NULL), rear(NULL) {}
template <class T> LinkQueue<T>::~LinkQueue() { clear(); }
template <class T> bool LinkQueue<T>::isEmpty() {
    if (front == NULL)
        return true;
    else
        return false;
}
template <class T> int LinkQueue<T>::getLength() {
    if (isEmpty())
        return 0;
    QueueNode<T> *p = front;
    int cnt = 0;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}
template <class T> T LinkQueue<T>::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    return front->data;
}
template <class T> bool LinkQueue<T>::EnQueue(T x) {
    if (front == NULL) {
        front = new QueueNode<T>(x, NULL);
        rear = front;
        return true;
    } else {
        QueueNode<T> *p = new QueueNode<T>(x, NULL);
        rear->next = p;
        rear = p;
        return true;
    }
}
template <class T> bool LinkQueue<T>::DeQueue(T &x) {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return false;
    }
    x = front->data;
    QueueNode<T> *p = front;
    front = front->next;
    delete (p);
}
template <class T> void LinkQueue<T>::print() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    QueueNode<T> *p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}
template <class T> void LinkQueue<T>::clear() {
    QueueNode<T> *p;
    while (front) {
        p = front;
        front = front->next;
        delete (p);
    }
}

#endif