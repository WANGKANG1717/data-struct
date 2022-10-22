/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: AVL
 * @filepath: cpp\AVL
 * @date: 2022-10-22 15:47:26
 * @description: AVL树的实现
 */
/**
 * @date: 2022-10-22 15:47:44
 * @description: 这个数据结构的代码基本不会考，我就是想写，没别的，加深下对
                 AVL树的理解
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 100
#define debug(x) cout << "x=" << (x) << endl

typedef struct Node {
    int data;
    Node *lchild, *rchild;
    Node() : lchild(NULL), rchild(NULL) {}
    Node(int data, Node *lchild = NULL, Node *rchild = NULL) : data(data), lchild(lchild), rchild(rchild) {}
} * AVLTree;
void insert(AVLTree &T, int x);
void create(AVLTree &T) {
    int N = 10;
    int data[N] = {7, 5, 2, 1, 3, 0, 4, 9, 6, 8};
    // cout << sizeof(data) / sizeof(int) << endl;
    for (int i = 0; i < N; i++) {
        insert(T, data[i]);
    }
    cout << "创建成功！" << endl;
}
/// @brief L代表顺时针， R代表逆时针
void L(AVLTree &T) {
    AVLTree p = T->lchild;
    T->lchild = p->rchild;
    p->rchild = T;
    T = p;
}
void R(AVLTree &T) {
    AVLTree p = T->rchild;
    T->rchild = p->lchild;
    p->lchild = T;
    T = p;
}
void LR(AVLTree &T) {
    R(T->lchild);
    L(T);
}
void RL(AVLTree &T) {
    L(T->rchild);
    R(T);
}
int getDepth(AVLTree T) {
    if (T == NULL) return 0;
    int l = getDepth(T->lchild);
    int r = getDepth(T->rchild);
    return max(l, r) + 1;
}
void insert(AVLTree &T, int x) {
    if (T == NULL) {
        T = new Node(x);
    } else if (x < T->data) {
        insert(T->lchild, x);
        int depL = getDepth(T->lchild);
        int depR = getDepth(T->rchild);
        //插入左边，肯定左边会高
        if (depL - depR == 2) {
            //说明查到T的左子树的左子树上了 LL
            if (x < (T->lchild->data)) {
                L(T);
            }
            // LR
            else {
                LR(T);
            }
        }
    } else if (x > T->data) {
        insert(T->rchild, x);
        int depL = getDepth(T->lchild);
        int depR = getDepth(T->rchild);
        if (depR - depL == 2) {
            if (x > (T->rchild->data)) {
                R(T);
            } else {
                RL(T);
            }
        }
    }
}
AVLTree search(AVLTree T, int x) {
    if (T) cout << T->data << " ";
    if (T == NULL || T->data == x)
        return T;
    else if (x < T->data)
        return search(T->lchild, x);
    else
        return search(T->rchild, x);
}
/**
 * @date: 2022-10-22 16:53:18
 * @description: 显示下能不能使用递归优雅的实现删除
 */
void remove(AVLTree &T, int x) {
    if (T == NULL)
        return;
    else if (T->data == x) {
        //第一种情况：叶子节点
        if (T->lchild == NULL && T->rchild == NULL) {
            AVLTree p = T;
            T = NULL;
            delete (p);
        }
        //第二种情况：左子树不为空，右子树为空
        else if (T->lchild != NULL && T->rchild == NULL) {
            AVLTree p = T;
            T = T->lchild;
            delete (p);
        }
        //第三种情况：左子树为空，右子树不为空
        else if (T->lchild == NULL && T->rchild != NULL) {
            AVLTree p = T;
            T = T->rchild;
            delete (p);
        }
        //第四种情况：左右字数均不为空
        else {
            //先找到T的后继节点
            AVLTree p = T->lchild;
            /**
             * @date: 2022-10-22 17:03:12
             * @description: 做到这里了，关键是想好如何实现替换与删除，吃饭去了
             */
        }
    } else if (x < T->data) {
        remove(T->lchild, x);
    } else {
        remove(T->rchild, x);
    }
}

int main() {
    AVLTree T = NULL;
    create(T);
    int x;
    while (cin >> x && x != -1) {
        cout << "搜索过程" << endl;
        AVLTree p = search(T, x);
        cout << "\n搜索结束" << endl;
        if (p)
            cout << p->data << endl;
    }

    return 0;
}