/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BST.cpp
 * @filepath: cpp\BST.cpp
 * @date: 2022-10-19 14:47:08
 * @description: 二叉搜索树
 */
/**
 * @date: 2022-10-20 15:19:02
 * @description: 二叉树的删除算法好难懂哦，还得好好学习下，必须搞懂！
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
//课本上直接使用数据交换了，我认为不好，试一下手动更换节点
void swap(Node *p, Node *r, Node *preP, Node *preR) {
    Node *rl = r->lchild;
    Node *rr = r->rchild;
    (preP->lchild == p) ? preP->lchild = r : preP->rchild = r;
    r->lchild = p->lchild;
    r->rchild = p->rchild;
    preR->rchild = p;
    p->lchild = rl;
    p->rchild = rr;
}

bool remove(int x) {
    Node *preP = NULL;
    Node *p = BST;
    while (p->data != x) {
        preP = p;
        if (x > p->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    if (p == NULL) {
        return false;
    }
    //如果被删的节点左右均不空
    if (p->lchild && p->rchild) {
        Node *preR = p;
        Node *r = p->lchild;
        //开始找最右下的节点
        while (r->rchild) {
            preR = r;
            r = r->rchild;
        }
        //交换被删节点与最右下节点
        // 说明右子树不空
        if (p->lchild == r) {
            (preP->lchild == p) ? preP->lchild = r : preP->rchild = r;
        } else {
            swap(p, r, preP, preR);
        }
        preP = preR;
    }
    //注意，这事p的左右子树中一定有一个空的
    if (preP == NULL)
        if (p->lchild) {
            p = p->lchild;
        } else if (p->rchild) {
            p = p->rchild;
        } else {
            (preP->lchild == p) ? preP->lchild = NULL : preP->rchild = NULL;
        }
    // 全部嫁接完成
    delete (p);
    if (BST == NULL)
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
    cout << "请输入要删除的数据（以-1结束）:" << endl;
    while (cin >> x && x != -1) {
        bool flag = remove(x);
        if (flag) {
            cout << "删除成功！" << endl;
        } else {
            cout << "删除失败！" << endl;
        }
    }

    return 0;
}