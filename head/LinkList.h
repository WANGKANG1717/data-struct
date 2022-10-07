/**
 * @filename: LinkList.h
 * @author: WangKang
 * @blog: kang17.xyz
 * @email: 1686617586@qq.com
 * @date: 2022-10-06 15:57:28
 * @description: ������ģ����
 */
#include "CustomException.h"

#include <cstddef>
#include <iostream>
using namespace std;

#ifndef __LinkList_H__
#define __LinkList_H__

/**
 * @date: 2022-10-06 16:02:19
 * @description: ��Ϊ�Ƚϼ�̣����Թ��캯��ֱ��д��������
 */

template <class T> class LinkNode {
  public:
    T data;
    LinkNode<T> *next;

    LinkNode() : next(NULL){};
    LinkNode(LinkNode<T> *next) : next(next) {}
    LinkNode(T data, T *next) : data(data), next(next) {}
    ~LinkNode();
};

/**
 * @date: 2022-10-06 16:03:23
 * @description: ��ͷ�ڵ�
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
    void create(int length);
    T getData(int index);
    LinkNode<T> *Locate(T x);
    bool isEmpty();
    void pre();
    void next();
    bool insert(int index);
    bool remove(int index);
    void removeAll();
    void print();
    void printAll();
};
template <class T> LinkList<T>::LinkList() {
    head = new LinkNode<T>(NULL);
    curr = tail = head;

    length = 0;
}

template <class T> LinkList<T>::~LinkList() { removeAll(); }

/**
 * @date: 2022-10-07 13:23:06
 * @description: β�巨����������
 */

template <class T> void LinkList<T>::create(int length) {
    T x;
    for (int i = 0; i < length; i++) {
        cin >> x;
        LinkNode<T> tmp = new LinkNode<T>(x, NULL);
        tail->next = tmp;
        tail = tmp;
        length++;
    }
}

template <class T> T LinkList<T>::getData(int index) {
    OutOfRange(length, index, 1);
    curr = head->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}


template <class T> void LinkList<T>::removeAll() {
    while(head->next) {
      LinkNode<T> *tmp=head->next;
      head->next=tmp->next;
      delete tmp;
    }
}

#endif