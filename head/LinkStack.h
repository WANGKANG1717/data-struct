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
  private:
    T data;
    LinkNode *next;

  public:
    LinkNode() next(NULL) {}
    LinkNode(T data, LinkNode<T> *next) : data(data), next(next) {}
    ~LinkNOde() {}
};

template <class T> class LinkStack {
  private:
    LinkNode *top;
    int length;

  public:
    LinkStack();
    ~LinkStack();
    bool isEmpty();
    void clear();
    int getLength();
    T getTop();
    bool Push(T x);
    T pop();
};

#endif