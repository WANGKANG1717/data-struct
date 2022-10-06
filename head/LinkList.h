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
  private:
    T data;
    T *next;

  public:
    LinkNode() { next = NULL; }
    LinkNode(T data, T *next) : data(data), next(next) {}
    ~LinkNode();
};

/**
 * @date: 2022-10-06 16:03:23
 * @description: 带头节点
 */
template <class T>
class LinkList {
  private:
    LinkNode<T> head;
    int length;     //当前链表中的节点个数
  public:
    LinkList(/* args */);
    ~LinkList();
};

LinkList::LinkList(/* args */) {}

LinkList::~LinkList() {}

#endif