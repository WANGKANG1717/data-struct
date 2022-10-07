/**
 * @filename: LinkList.h
 * @author: WangKang
 * @blog: kang17.xyz
 * @email: 1686617586@qq.com
 * @date: 2022-10-06 15:57:28
 * @description: 单链表模板类
 */
#include "CustomException.h"

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __LinkList_H__
#define __LinkList_H__

/**
 * @date: 2022-10-06 16:02:19
 * @description: 因为比较简短，所以构造函数直接写在里面了
 */

template <class T> class LinkNode {
  public:
    T data;
    LinkNode<T> *next;

    LinkNode(LinkNode<T> *next = NULL) : next(next) {}
    LinkNode(T data, LinkNode<T> *next) : data(data), next(next) {}
    ~LinkNode(){};
};

/**
 * @date: 2022-10-06 16:03:23
 * @description: 带头节点
 */
template <class T> class LinkList : public LinkNode<T> {
  private:
    LinkNode<T> *head;
    LinkNode<T> *tail;
    LinkNode<T> *curr;
    int length;

    inline void checkRange() const;
    inline void checkRange(int index) const;

  public:
    LinkList();
    ~LinkList();
    //
    void create(T data[], int n);
    T getData(int index);
    LinkNode<T> *Locate(T x);
    bool isEmpty();
    void pre();
    void next();
    bool insert(int index);
    bool remove(int index);
    void removeAll();
    void print();
    int getLength();
};

template <class T> LinkList<T>::LinkList() {
    head = new LinkNode<T>(NULL);
    curr = tail = head;

    length = 0;
}

template <class T> LinkList<T>::~LinkList() { removeAll(); }

template <class T> inline void LinkList<T>::checkRange() const {
    if (length == 0) {
        throw OutOfRange(1);
    }
}

template <class T> inline void LinkList<T>::checkRange(int index) const {
    if (length == 0) {
        throw OutOfRange(1);
    } else if (index < 0 || index >= length) {
        throw OutOfRange(length, index, 1);
    }
}

/**
 * @date: 2022-10-07 13:23:06
 * @description: 尾插法创建单链表
 */

template <class T> void LinkList<T>::create(T data[], int n) {
    T x;
    for (int i = 0; i < n; i++) {
        LinkNode<T> *tmp = new LinkNode<T>(data[i], NULL);
        tail->next = tmp;
        tail = tmp;
        length++;
    }
}

template <class T> T LinkList<T>::getData(int index) {
    checkRange(index);
    curr = head->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template <class T> void LinkList<T>::removeAll() {
    while (head->next) {
        LinkNode<T> *tmp = head->next;
        head = tmp->next;
        delete tmp;
    }
    tail = curr = head;
}

template <class T> void LinkList<T>::print() {
    LinkNode<T> *p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class T> bool LinkList<T>::isEmpty() {
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}
template <class T> int LinkList<T>::getLength() { return length; }

template <class T> LinkNode<T> *LinkList<T>::Locate(T x) {
    checkRange();
    LinkNode<T> *p = head->next;
    for (int i = 0; i < length; i++, p=p->next) {
        if (p->data == x) {
            break;
        }
    }
    return p;
}

#endif