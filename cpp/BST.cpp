/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BST.cpp
 * @filepath: cpp\BST.cpp
 * @date: 2022-10-19 14:47:08
 * @description: 二叉搜索树
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
    Node() : lchild(NULL), rchild(NULL){};
    Node(int data, Node *lchild = NULL, Node *rchild = NULL) : data(data), lchild(lchild), rchild(rchild) {}
};
Node *BST = NULL;

void insert(Node *&T, int x) {
    if (T == NULL) {
        T = new Node(x);
        return;
    } else if (x < T->data) {
        insert(T->lchild, x);
    } else {
        insert(T->rchild, x);
    }
}

void create() {
    int Data[15] = {20, 24, 50, 57, 87, 94, 96,
                    67, 14, 66, 95, 82, 42, 31, 26};
    for (int i = 0; i < 15; i++) {
        insert(BST, Data[i]);
    }
}

Node *search(Node *T, int x) {
    if (T == NULL) {
        return NULL;
    } else if (T->data == x) {
        return T;
    } else if (x < T->data) {
        return search(T->lchild, x);
    } else {
        return search(T->rchild, x);
    }
}
void remove(int x) {
}
int main() {
    create();
    if (BST == NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    int x;
    cout << "请输入要查找的数据(以-1结束):" << endl;
    Node *p;
    while (cin >> x && x != -1) {
        p = search(BST, x);
        if (p)
            cout << p->data << endl;
        else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}