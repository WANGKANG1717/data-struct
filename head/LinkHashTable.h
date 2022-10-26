/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: LinkHashTable.h
 * @filepath: head\LinkHashTable.h
 * @date: 2022-10-25 13:43:24
 * @description: 连地址法解决冲突
 */
/**
 * @date: 2022-10-25 14:00:13
 * @description: 忽然发现之前的哈希表还有点问题，需要搞一下
 */

#ifndef __LINKHASHTABLE_H__
#define __LINKHASHTABLE_H__
#include <iostream>
using namespace std;
class Node {
   public:
    int data;
    int key;
    Node *next;
    Node() : next(NULL){};
    Node(int data, int key, Node *next = NULL) : data(data), key(key), next(next){};
    ~Node(){};
    friend ostream &operator<<(ostream &out, Node a) {
        out << a.data << " " << a.key;
        return out;
    };
};
/**
 * @date: 2022-10-26 13:07:23
 * @description: 不带头节点的欧
 */
class LinkHashTable {
   private:
    Node **table;
    int M;
    void Clear(Node *&p);

   public:
    LinkHashTable(int M = 10);
    ~LinkHashTable();
    bool insert(int x);
    bool remove(int x);
    Node *search(int x);
    void clear();
    int getKey(int x);
    bool contain(int x);
    void print();
};

LinkHashTable::LinkHashTable(int M) {
    this->M = M;
    this->table = new Node *[M]();
}
LinkHashTable::~LinkHashTable() {
    clear();
    delete[] table;
}

void LinkHashTable::clear() {
    for (int i = 0; i < M; i++) {
        Clear(table[i]);
    }
}
void LinkHashTable::Clear(Node *&f) {
    Node *p = f;
    while (p) {
        Node *tmp = p;
        p = p->next;
        delete tmp;
    }
    f = NULL;
}
int LinkHashTable::getKey(int x) {
    return x % M;
}
/**
 * @date: 2022-10-26 13:09:22
 * @description: 头插法，不带头节点
 */
bool LinkHashTable::insert(int x) {
    if (contain(x)) {
        cout << "Allready in table!" << endl;
        return false;
    }
    int Key = getKey(x);
    Node *p = new Node(x, Key, table[Key]);
    if (table[Key] == NULL) {
        table[Key] = p;
    } else {
        p->next = table[Key];
        table[Key] = p;
    }
    return true;
}

bool LinkHashTable::contain(int x) {
    int Key = getKey(x);
    Node *p = table[Key];
    int flag = false;
    while (p) {
        if (p->data != x)
            p = p->next;
        else {
            flag = true;
            break;
        }
    }
    return flag;
}
Node *LinkHashTable::search(int x) {
    int Key = getKey(x);
    Node *p = table[Key];
    while (p) {
        if (p->data == x) break;
        p = p->next;
    }
    return p;
}

bool LinkHashTable::remove(int x) {
    if (!contain(x)) {
        cout << "Not in Table!" << endl;
    }
    int Key = getKey(x);
    Node *pre = NULL;
    Node *p = table[Key];
    while (p) {
        if (p->data == x) {
            //说明头节点要修改
            if (pre == NULL) {
                table[Key] = p->next;
            } else {
                pre->next = p->next;
            }
            delete (p);
            break;
        } else {
            pre = p;
            p = p->next;
        }
    }
    return true;
}

void LinkHashTable::print() {
    cout << "---------------LinkHashTable Print-------------" << endl;
    for (int i = 0; i < M; i++) {
        cout << i << ":" << endl;
        Node *p = table[i];
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    cout << "---------------LinkHashTable Print-------------" << endl;
}
#endif
