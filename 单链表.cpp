/**
 * @filename: 单链表.cpp
 * @author: WangKang
 * @email: 1686617586@qq.com
 * @date: 2022-07-19 17:12:10
 * @description: 递归逆转单链表
 */

#include<iostream>
using namespace std;
/**
 * 最终决定使用模板类来实现所有算法
 */



typedef struct {
    int data;
    LinkList *next;
} LNode, *LinkList;

Status InitLinkList(LinkList &L) {
    L=new LNode;
    L->next==NULL;
    return OK;
}
Status getElem(LinkList L, int i, ElemType &e) {
    int j=1;
    LinkList p=L->next;
    while(p && j<i) {
        p=p->next;
        j++;
    }
    if(!p || j>i) {
        return ERROR;
    }
    e=p->data;
    return OK;
}
LNode* LocateElem(LinkList L, ElemType e) {
    LinkList p=L->next;
    while(p->data!=e) {
        p=p->next;
    }
    return p;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    LinkList p=L;
    int j=0;
    while(p && j<i-1) {
        p=p->next;
        j++;
    }
    if(!p || j>i-1) return ERROR;
    LinkList s=new LNode();
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ListDelete(LinkList &L, int i) {
    LinkList p=L;
    int j=0;
    while(p->next && j<i-1) {
        p=p->next;
        j++;
    }
    if(!p->next || j>i-1) return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    delete(q);
    return OK;
}

void CreateList_H(LinkList &L, int n) {
    L=new LNode;
    L->next=NULL;
    LinkList p=NULL;
    int data;
    for(int i=0; i<n; i++) {
        p=new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}

void CreateList_R(LinkList &L, int n) {
    L=new LNode;
    L->next=NULL;
    LinkList r=L;
    LinkList p=NULL;
    int data;
    for(int i=0; i<n; i++) {
        p=new LNode;
        p->next=NULL;
        cin>>p->data;
        r->next=p;
        r=p;
    }
}
// LinkList createList() {
//     int data;
//     LinkList *head;
//     LinkList *p=NULL;
//     head=p;
//     while(cin>>data) {
//         LinkList *tmp=new LinkList();
//         tmp->data=data;
//         tmp->next=new LinkList();
//         tmp->next=NULL;
//         if(p==NULL) p=tmp, head=p;
//         else p->next=tmp, p=tmp;
//     }
//     return head;
// }
// void showList(LinkList* p) {
//     while(p) {
//         cout<<p->data<<" ";
//         p=p->next;
//     }
//     cout<<endl;
// }
// //递归
// LinkList* reverseList(LinkList *p) {
//    //递归出口，需要返回递归出口处的指针，作为头节点指针
//    LinkList *newHead=NULL;
//     if(p==NULL || p->next==NULL) {
//         newHead=p;
//     }
//     else {
//         //指向当前节点的后一个
//         LinkList *back=p->next;
//         newHead=reverseList(p->next);
//         //这里逆转
//         back->next=p;
//         p->next=NULL;
//     }
//     return newHead;
// }
// //非递归
// LinkList* reverseList2(LinkList *p) {
//     //头节点为空，或者只有一个节点，没必要逆转
//    if(!p || p->next==NULL) return p;
//    LinkList *pre, *cur, *back;
//    pre=NULL;
//    cur=p;
//    back=cur->next;
//    while(cur!=NULL) {
//        cur->next=pre;
//        pre=cur;
//        cur=back;
//        if(back->next!=NULL) back=back->next;
//    }
//    return pre;
// }
int main() {
    LinkList p=createList();
    showList(p);
    p=reverseList2(p);
    showList(p);
}