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
    int data[N] = {5, 2, 7, 1, 4, 6, 8, 0, 3, 9};
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
/**
 * @date: 2022-10-23 14:14:24
 * @description: 干的漂亮，使用数据替换，进而避免麻烦的节点交换
 *                 使用指针引用，进入是心啊方便的删除节点，NICE！
 */
/**
 * @date: 2022-10-23 14:34:13
 * @description: 终于，我把AVL树的删除搞定了！
 */
bool remove(AVLTree &T, int x) {
    if (T == NULL)
        return false;
    else if (T->data == x) {
        /**
         * @date: 2022-10-23 14:26:30
         * @description: 这三种情况可以合三为一
         */
        //第一种情况：叶子节点
        if (T->lchild == NULL && T->rchild == NULL) {
            AVLTree p = T;
            T = NULL;
            delete (p);
            return true;
        }
        //第二种情况：左子树不为空，右子树为空
        else if (T->lchild != NULL && T->rchild == NULL) {
            AVLTree p = T;
            T = T->lchild;
            delete (p);
            return true;
        }
        //第三种情况：左子树为空，右子树不为空
        else if (T->lchild == NULL && T->rchild != NULL) {
            AVLTree p = T;
            T = T->rchild;
            delete (p);
            return true;
        }
        //第四种情况：左右字数均不为空
        else {
            //先找到T的后继节点
            AVLTree p = T->lchild, r;
            /**
             * @date: 2022-10-22 17:03:12
             * @description: 做到这里了，关键是想好如何实现替换与删除，吃饭去了
             */
            while (p->rchild) {
                p = p->rchild;
            }
            //不交换节点了，太麻烦了，调试又难
            int tmp = p->data;
            p->data = T->data;
            T->data = tmp;
        }
    }
    //因为上面可能进行节点的数据的调换，所以这里使用这种操作，统一
    int flag = false;
    if (x < T->data) {
        flag = remove(T->lchild, x);
        int depL = getDepth(T->lchild);
        int depR = getDepth(T->rchild);
        //这种情况下肯定左子树变小了
        if (depR - depL == 2) {
            if (T->rchild->rchild != NULL) {
                R(T);
                cout << "R()" << endl;
            } else {
                RL(T);
                cout << "RL()" << endl;
            }
        }
    } else if (x > T->data) {
        flag = remove(T->rchild, x);
        int depL = getDepth(T->lchild);
        int depR = getDepth(T->rchild);
        //这种情况下肯定右子树变小了
        if (depL - depR == 2) {
            if (T->lchild->lchild != NULL) {
                L(T);
                cout << "L(T)" << endl;
            } else {
                LR(T);
                cout << "LR(T)" << endl;
            }
        }
    }
    return flag;
}

int main() {
    AVLTree AVLT = NULL;
    create(AVLT);
    int x;
    // while (cin >> x && x != -1) {
    //     cout << "搜索过程" << endl;
    //     AVLTree p = search(T, x);
    //     cout << "\n搜索结束" << endl;
    //     if (p)
    //         cout << p->data << endl;
    // }
    while (cin >> x && x != -1) {
        bool flag = remove(AVLT, x);
        if (flag == true) {
            cout << "移除成功" << endl;
        } else {
            cout << "移除失败" << endl;
        }
    }

    return 0;
}