/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: LinkList.h
 * @date: 2022-10-08 14:09:40
 * @description: 单链表头文件
 */
/**
 * 不再使用异常，麻烦
 */
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

  public:
    LinkList();
    ~LinkList();
    //
    void create(T data[], int n);
    bool getData(int index, T &data);
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

template <class T> bool LinkList<T>::getData(int index, T &data) {
    if (index < 0 || index > length) {
        cout << "Error: out of Range";
        return false;
    }

    curr = head->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    data = curr->data;
    return true;
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
    if (length == 0) {
        cout << "Error: Empty LinkList!" << endl;
        return NULL;
    }
    LinkNode<T> *p = head->next;
    for (int i = 0; i < length; i++, p = p->next) {
        if (p->data == x) {
            break;
        }
    }
    return p;
}

#endif