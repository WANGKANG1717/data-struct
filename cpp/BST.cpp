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
    int n = 10;
    // int Data[n] = {5, 2, 1, 3, 4, 9, 8, 7, 6, 10};
    // int Data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Data[n] = {5, 2, 1, 3, 4, 9, 6, 7, 8, 10};
    for (int i = 0; i < n; i++) {
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
/**
 * @date: 2022-10-21 16:16:57
 * @description: 调试了好久，应该没什么问题了
 */
bool remove(int x) {
    Node *preP = NULL;
    Node *p = BST;
    while (p && p->data != x) {
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
        // r指的是要删除节点的左孩子的最有下节点，也就是p的先驱
        Node *preR = p;
        Node *r = p->lchild;
        //开始找最右下的节点
        while (r->rchild) {
            preR = r;
            r = r->rchild;
        }
        //交换被删节点与最右下节点
        // 说明右子树不空
        if (preR == p) {
            r->rchild = p->rchild;
            (preP->lchild == p) ? preP->lchild = r : preP->rchild = r;
            delete (p);
        } else {
            // 说明需要交换节点
            /**
             * @date: 2022-10-21 15:13:27
             * @description: 可知r的右节点一定为空。
             */
            // Node *rl = r->lchild;
            preR->rchild = r->lchild;
            //如果要删除的节点不为为根节点
            r->lchild = p->lchild;
            r->rchild = p->rchild;
            //考虑到有可能删掉根节点，需要重新链接根节点
            if (preP == NULL) {
                BST = r;
            } else {
                (preP->lchild == p) ? preP->lchild = r : preP->rchild = r;
            }
            //重接preR的右子树为r的左子树
            delete (p);
        }
    } else {
        /**
         * @date: 2022-10-21 15:21:22
         * @description: 将剩余的三种情况统一为一种情况
         */
        Node *P = p->lchild ? p->lchild : p->rchild;
        if (preP == NULL) {
            BST = P;
        } else {
            (preP->lchild == p) ? preP->lchild = P : preP->rchild = P;
        }
        delete (p);
    }
    return true;
}
int main() {
    create();
    if (BST == NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    int x;
    // cout << "请输入要查找的数据(以-1结束):" << endl;
    // Node *p;
    // while (cin >> x && x != -1) {
    //     p = search(BST, x);
    //     if (p)
    //         cout << p->data << endl;
    //     else {
    //         cout << "Not Found!" << endl;
    //     }
    // }
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