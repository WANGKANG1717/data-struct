/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: LinkStack
 * @filepath: head\LinkStack
 * @date: 2022-10-09 14:57:52
 * @description: 链栈
 */

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

template <class T> class LinkNode {
  public:
    T data;
    LinkNode<T> *next;

    LinkNode() : next(NULL) {}
    LinkNode(T data, LinkNode<T> *next) : data(data), next(next) {}
    ~LinkNode() {}
};

template <class T> class LinkStack {
  private:
    LinkNode<T> *top;
    int length;

  public:
    LinkStack();
    ~LinkStack();
    bool isEmpty();
    void clear();
    int getLength();
    T getTop();
    bool push(T x);
    T pop();
};
template <class T> LinkStack<T>::LinkStack() {
    top = new LinkNode<T>();
    length = 0;
}
template <class T> LinkStack<T>::~LinkStack() { clear(); }

template <class T> bool LinkStack<T>::isEmpty() {
    if (top->next == NULL)
        return true;
    else
        return false;
}
template <class T> void LinkStack<T>::clear() {
    LinkNode<T> *p;
    while (top->next) {
        p = top->next;
        top->next = p->next;
        length--;
        delete (p);
    }
}
template <class T> int LinkStack<T>::getLength() { return length; }
template <class T> T LinkStack<T>::getTop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return NULL;
    }
    return top->next->data;
}
template <class T> bool LinkStack<T>::push(T x) {
    LinkNode<T> *p = new LinkNode<T>(x, top->next);
    top->next = p;
    length++;
    return true;
}
template <class T> T LinkStack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return NULL;
    }
    LinkNode<T> *p = top->next;
    top->next = p->next;
    T x = p->data;
    delete (p);
    length--;
    return x;
}

#endif