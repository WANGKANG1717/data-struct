/**
 * @filename: LinkList.h
 * @author: WangKang
 * @blog: kang17.xyz
 * @email: 1686617586@qq.com
 * @date: 2022-10-06 15:57:28
 * @description: ������ģ����
 */
/**
 * ����ʹ���쳣���鷳
 */
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

    LinkNode(LinkNode<T> *next = NULL) : next(next) {}
    LinkNode(T data, LinkNode<T> *next) : data(data), next(next) {}
    ~LinkNode(){};
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

/**
 * @date: 2022-10-07 13:23:06
 * @description: β�巨����������
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
    if (index < 0 || index > length) {
        cout << "Error: out of Range";
        return NULL;
    }

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
    if (length == 0) {
        cout << "Error: Empty LinkList!" << endl;
        return;
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