/**
 * @filename: ��������ת.cpp
 * @author: WangKang
 * @email: 1686617586@qq.com
 * @date: 2022-07-19 17:12:10
 * @description: �ݹ���ת������
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
//�ݹ�
LinkList *reverseList(LinkList *p) {
    //�ݹ���ڣ���Ҫ���صݹ���ڴ���ָ�룬��Ϊͷ�ڵ�ָ��
    LinkList *newHead = NULL;
    if (p == NULL || p->next == NULL) {
        newHead = p;
    } else {
        //ָ��ǰ�ڵ�ĺ�һ��
        LinkList *back = p->next;
        newHead = reverseList(p->next);
        //������ת
        back->next = p;
        p->next = NULL;
    }
    return newHead;
}
//�ǵݹ�
LinkList *reverseList2(LinkList *p) {
    //ͷ�ڵ�Ϊ�գ�����ֻ��һ���ڵ㣬û��Ҫ��ת
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
     * @description: ��Ǯ������
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