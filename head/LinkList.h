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
 * @description: ��ͷ�ڵ�
 */
template <class T>
class LinkList {
  private:
    LinkNode<T> head;
    int length;     //��ǰ�����еĽڵ����
  public:
    LinkList(/* args */);
    ~LinkList();
};

LinkList::LinkList(/* args */) {}

LinkList::~LinkList() {}

#endif