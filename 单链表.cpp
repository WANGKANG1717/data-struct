/**
 * @filename: ������.cpp
 * @author: WangKang
 * @email: 1686617586@qq.com
 * @date: 2022-07-19 17:12:10
 * @description: �ݹ���ת������
 */

#include<iostream>
using namespace std;
/**
 * ���վ���ʹ��ģ������ʵ�������㷨
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
// //�ݹ�
// LinkList* reverseList(LinkList *p) {
//    //�ݹ���ڣ���Ҫ���صݹ���ڴ���ָ�룬��Ϊͷ�ڵ�ָ��
//    LinkList *newHead=NULL;
//     if(p==NULL || p->next==NULL) {
//         newHead=p;
//     }
//     else {
//         //ָ��ǰ�ڵ�ĺ�һ��
//         LinkList *back=p->next;
//         newHead=reverseList(p->next);
//         //������ת
//         back->next=p;
//         p->next=NULL;
//     }
//     return newHead;
// }
// //�ǵݹ�
// LinkList* reverseList2(LinkList *p) {
//     //ͷ�ڵ�Ϊ�գ�����ֻ��һ���ڵ㣬û��Ҫ��ת
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