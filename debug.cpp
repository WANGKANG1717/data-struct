/**
 * @filename: 单链表逆转.cpp
 * @author: WangKang
 * @email: 1686617586@qq.com
 * @date: 2022-07-19 17:12:10
 * @description: 递归逆转单链表
 */

#include <iostream>
using namespace std;
struct LinkList {
    int data;
    LinkList *next;
};
LinkList *createList() {
    int data;
    LinkList *head;
    LinkList *p = NULL;
    head = p;
    while (cin >> data) {
        LinkList *tmp = new LinkList();
        tmp->data = data;
        tmp->next = new LinkList();
        tmp->next = NULL;
        if (p == NULL)
            p = tmp, head = p;
        else
            p->next = tmp, p = tmp;
    }
    return head;
}
void showList(LinkList *p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//递归
LinkList *reverseList(LinkList *p) {
    //递归出口，需要返回递归出口处的指针，作为头节点指针
    LinkList *newHead = NULL;
    if (p == NULL || p->next == NULL) {
        newHead = p;
    } else {
        //指向当前节点的后一个
        LinkList *back = p->next;
        newHead = reverseList(p->next);
        //这里逆转
        back->next = p;
        p->next = NULL;
    }
    return newHead;
}
//非递归
LinkList *reverseList2(LinkList *p) {
    //头节点为空，或者只有一个节点，没必要逆转
    if (!p || p->next == NULL)
        return p;
    LinkList *pre, *cur, *back;
    pre = NULL;
    cur = p;
    back = cur->next;
    while (cur != NULL) {
        cur->next = pre;
        pre = cur;
        cur = back;
        if (back != NULL)
            back = back->next;
    }
    return pre;
}

#define ll long
typedef char ch;
int main() {
    /**
     * @filename: debug.cpp
     * @author: WangKang
     * @email: 1686617586@qq.com
     * @date: 2022-07-20 17:50:12
     * @description: 百钱买鸡问题
     */
    
    // for (int i = 0; i < 20; i++) {
    //     for (int j = 0; j < 33; j++) {
    //         if ((5 * i + 3 * j + (100 - i - j) / 3) == 100 &&
    //             (100 - i - j) % 3 == 0) {
    //             cout << i << " " << j << " " << (100 - i - j) << endl;
    //         }
    //     }
    // }
    ll a;
    ch b;
    b='3';
    cout<<b<<endl;
}