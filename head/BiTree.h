/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BiTree.h
 * @filepath: head\BiTree.h
 * @date: 2022-10-13 13:00:50
 * @description: 树
 */

/**
 * @date: 2022-10-14 13:30:26
 * @description: 指针引用 *& 指针 是有区别的，需要记住
 */

#ifndef __BITREE_H__
#define __BITREE_H__
#include <iostream>
#include <map>
#define MAXINT 0x7f7f7f7f
#include "../head/LinkQueue.h"
#include "../head/LinkStack.h"
using namespace std;
#define MAXINT 0x7f7f7f7f
#define MININT -0x7f7f7f7f
template <class T>
class BiNode {
   public:
    T data;
    BiNode<T> *lchild, *rchild;
    BiNode() : lchild(NULL), rchild(NULL) {}
    BiNode(T data, BiNode<T> *lchild = NULL, BiNode<T> *rchild = NULL)
        : data(data), lchild(lchild), rchild(rchild) {}
    ~BiNode(){};
    /**
     * @date: 2022-10-13 13:14:33
     * @description: 不搞这些，太麻烦了，得不偿失
     */
    // BiNode<T> *lchild();
    // BiNode<T> *rchild();
    // void setLchild();
    // void setRchild();
    // void setLchildVal();
    // void setRchildVal();
};

template <class T>
class BiTree : public BiNode<T> {
   private:
    BiNode<T> *root;

    BiNode<T> *getParent(BiNode<T> *curr, BiNode<T> *pre, BiNode<T> *target);
    BiNode<T> *getLeftSibing(BiNode<T> *curr, BiNode<T> *target);
    BiNode<T> *getRightSibing(BiNode<T> *curr, BiNode<T> *target);

   public:
    BiTree();   //
    ~BiTree();  ////
    void clear();
    void Clear(BiNode<T> *&Root);  //
    /**
     * @date: 2022-10-13 13:27:03
     * @param: data; i:下标; n: 总的数据大小; endFlag 自定义的结束标志
     * @return: NULL
     * @description: 传一个大小为n的数组，要求前序遍历存储，以#结尾，作为空节点
     */
    /**
     * @date: 2022-10-14 13:31:22
     * @description:
     * 搞这个函数的时候，感觉写的很对，死活出不来，原来是指针引需要引用的原因
     */
    /**
     * @date: 2022-10-14 13:55:28
     * @description: 注
     * create函数最好再封装一下，这里由于时间问题，直接忽略，能用就行，重点再了解其思想
     */
    void create(BiNode<T> *&Root, T *data, T endFlag, int &i, int n);  //
    /**
     * @date: 2022-10-13 13:28:50
     * @param: root
     * @return: NULL
     * @description: 根据提示按照前序序列创建二叉树
     */
    void create(T endFlag);                  //
    BiNode<T> *Create(T endFlag);            //
    bool isEmpty();                          //
    int getDepth();                          //
    int GetDepth(BiNode<T> *Root, int dep);  //
    BiNode<T> *&getRoot();                   //
    void preOrder(BiNode<T> *Root);          //
    void preOrder2();                        //
    void inOrder(BiNode<T> *Root);           //
    void inOrder2();                         //
    void postOrder(BiNode<T> *Root);         //
    void postOrder2();                       //
    void levelOrder();                       //
    /**
     * @date: 2022-10-14 15:09:55
     * @description:
     * 最后八个函数，搞定之后开始图的算法，然后是查找，排序，还有一个哈夫曼树
     */
    /**
     * @date: 2022-10-15 13:29:11
     * @description: 本来这里的内置内置函数应该放到private里面的，暂时不搞
     */
    int nodeCount();                  //总节点 //
    int NodeCount(BiNode<T> *Root);   //总节点//
    int nodeCount0();                 //总节点//
    int NodeCount0(BiNode<T> *Root);  //
    int nodeCount1();                 //度为一的节点//
    int NodeCount1(BiNode<T> *Root);  //
    int nodeCount2();                 //度为二的节点//
    int NodeCount2(BiNode<T> *Root);  //
    /**
     * @date: 2022-10-15 13:31:34
     * @description: 树的创建
     */
    void createTree_Use_Pre_In_Order(T *preOrder, T *inOrder, int n);                       //
    BiNode<T> *CreateTree_Use_Pre_In_Order(T *inOrder, map<T, int> &w, int low, int high);  //

    void createTree_Use_Post_In_Order(T *postOrder, T *inOrder, int n);                      //
    BiNode<T> *CreateTree_Use_Post_In_Order(T *inOrder, map<T, int> &w, int low, int high);  //
    /**
     * @date: 2022-10-15 15:20:40
     * @description: 还剩最后一个函数，这个函数我之前灭有写过，试一下吧
     */
    /**
     * @date: 2022-10-15 15:29:38
     * @description: 全部搞定，树到一段落，至于二叉搜索树和二叉平衡树，我会再搜索那一章节里写
     */
    void createTree_Use_Level_In_Order(T *levelOrder, T *inOrder, int n);
    BiNode<T> *CreateTree_Use_Level_In_Order(T *inOrder, map<T, int> &w, int low, int high);
};
template <class T>
BiTree<T>::BiTree() : root(NULL) {}

template <class T>
BiTree<T>::~BiTree() {
    Clear(root);
}

template <class T>
void BiTree<T>::clear() {
    if (root == NULL)
        return;
    Clear(root);
    root = NULL;
}

template <class T>
void BiTree<T>::Clear(BiNode<T> *&r) {
    if (r == NULL)
        return;
    Clear(r->lchild);
    Clear(r->rchild);
    delete (r);
}

template <class T>
void BiTree<T>::create(BiNode<T> *&Root, T *data, T endFlag, int &i, int n) {
    if (data[i] == endFlag) {
        Root = NULL;
        return;
    }
    Root = new BiNode<T>(data[i]);
    i++;
    create(Root->lchild, data, endFlag, i, n);
    i++;
    create(Root->rchild, data, endFlag, i, n);
}
/**
 * @date: 2022-10-13 15:18:41
 * @description: 娘娘的，非得这样才行，真是花了好长时间才调试出来
 *          如果使用传统的递归方式的话，不知道为什么，就是出不来
 */
template <class T>
void BiTree<T>::create(T endFlag) {
    root = Create(endFlag);
}
template <class T>
BiNode<T> *BiTree<T>::Create(T endFlag) {
    T x;
    cin >> x;
    if (x == endFlag) {
        return NULL;
    }
    BiNode<T> *Root = new BiNode<T>(x);
    Root->lchild = Create(endFlag);
    Root->rchild = Create(endFlag);
    return Root;
}

template <class T>
bool BiTree<T>::isEmpty() {
    if (root == NULL) {
        return true;
    } else
        return false;
}
template <class T>
int BiTree<T>::getDepth() {
    return GetDepth(root, 0);
}
template <class T>
int BiTree<T>::GetDepth(BiNode<T> *Root, int dep) {
    if (Root == NULL)
        return 0;
    int ldep = GetDepth(Root->lchild, dep + 1);
    int rdep = GetDepth(Root->rchild, dep + 1);
    return max(ldep, rdep) + 1;
}

template <class T>
BiNode<T> *&BiTree<T>::getRoot() {
    return root;
}

template <class T>
void BiTree<T>::preOrder(BiNode<T> *Root) {
    if (Root) {
        cout << Root->data << " ";
        preOrder(Root->lchild);
        preOrder(Root->rchild);
    }
}
template <class T>
void BiTree<T>::preOrder2() {
    // cout << "---------------------" << endl;
    // cout << "preOrder2:" << endl;
    LinkStack<BiNode<T> *> S;
    BiNode<T> *p = NULL;
    if (root != NULL) {
        p = root;
    }
    while (!S.isEmpty() || p) {
        while (p) {
            cout << p->data << " ";
            S.push(p);
            p = p->lchild;
        }
        p = S.getTop();
        S.pop();
        p = p->rchild;
    }

    // cout << "\n---------------------" << endl;
}

template <class T>
void BiTree<T>::inOrder(BiNode<T> *Root) {
    if (Root) {
        inOrder(Root->lchild);
        cout << Root->data << " ";
        inOrder(Root->rchild);
    }
}
template <class T>
void BiTree<T>::inOrder2() {
    // cout << "---------------------" << endl;
    // cout << "InOrder2:" << endl;
    LinkStack<BiNode<T> *> S;
    BiNode<T> *p = NULL;
    if (root != NULL) {
        p = root;
    }
    while (!S.isEmpty() || p) {
        while (p) {
            S.push(p);
            p = p->lchild;
        }
        if (!S.isEmpty()) {
            p = S.getTop();
            S.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }

    // cout << "\n---------------------" << endl;
}

template <class T>
void BiTree<T>::postOrder(BiNode<T> *Root) {
    if (Root) {
        postOrder(Root->lchild);
        postOrder(Root->rchild);
        cout << Root->data << " ";
    }
}
template <class T>
void BiTree<T>::postOrder2() {
    LinkStack<BiNode<T> *> S;
    if (root == NULL)
        return;
    BiNode<T> *p = root;
    /**
     * @date: 2022-10-14 14:13:42
     * @description: 使用指针引用，不会创建新的指针
     */
    map<BiNode<T> *, int> vis;
    while (!S.isEmpty() || p) {
        while (p) {
            S.push(p);
            p = p->lchild;
        }
        if (!S.isEmpty()) {
            p = S.getTop();
            vis[p]++;
            if (vis[p] == 2) {
                cout << p->data << " ";
                S.pop();
                p = NULL;  //神来之笔
            } else {
                p = p->rchild;
            }
        }
    }
}
template <class T>
void BiTree<T>::levelOrder() {
    // cout << "---------------------" << endl;
    // cout << "LevelOrder:" << endl;
    LinkQueue<BiNode<T> *> Q;
    if (root != NULL) {
        Q.EnQueue(root);
    }
    BiNode<T> *p;
    while (!Q.isEmpty()) {
        Q.DeQueue(p);
        cout << p->data << " ";
        if (p->lchild) {
            Q.EnQueue(p->lchild);
        }
        if (p->rchild) {
            Q.EnQueue(p->rchild);
        }
    }
    // cout << "\n-----------------------\n";
}

template <class T>
int BiTree<T>::nodeCount() {
    return NodeCount(root);
}
template <class T>
int BiTree<T>::NodeCount(BiNode<T> *Root) {
    if (Root == NULL)
        return 0;
    else
        return NodeCount(Root->lchild) + NodeCount(Root->rchild) + 1;
}

template <class T>
int BiTree<T>::nodeCount0() {
    return NodeCount0(root);
}
template <class T>
int BiTree<T>::NodeCount0(BiNode<T> *Root) {
    if (Root == NULL)
        return 0;
    else if (Root->lchild == NULL && Root->rchild == NULL)
        return 1;
    else
        return NodeCount0(Root->lchild) + NodeCount0(Root->rchild);
}
template <class T>
int BiTree<T>::nodeCount1() {
    return NodeCount1(root);
}
template <class T>
int BiTree<T>::NodeCount1(BiNode<T> *Root) {
    if (Root == NULL)
        return 0;
    else if ((Root->lchild == NULL && Root->rchild != NULL) ||
             (Root->lchild != NULL && Root->rchild == NULL))
        return NodeCount1(Root->lchild) + NodeCount1(Root->rchild) + 1;
    else
        return NodeCount1(Root->lchild) + NodeCount1(Root->rchild);
}
template <class T>
int BiTree<T>::nodeCount2() {
    return NodeCount2(root);
}
template <class T>
int BiTree<T>::NodeCount2(BiNode<T> *Root) {
    if (Root == NULL)
        return 0;
    else if (Root->lchild && Root->rchild)
        return NodeCount2(Root->lchild) + NodeCount2(Root->rchild) + 1;
    else
        return NodeCount2(Root->lchild) + NodeCount2(Root->rchild);
}

template <class T>
void BiTree<T>::createTree_Use_Pre_In_Order(T *preOrder, T *inOrder, int n) {
    map<T, int> w;
    for (int i = 0; i < n; i++) {
        w[preOrder[i]] = i;
    }
    root = CreateTree_Use_Pre_In_Order(inOrder, w, 0, n - 1);
}
template <class T>
BiNode<T> *BiTree<T>::CreateTree_Use_Pre_In_Order(T *inOrder, map<T, int> &w, int low, int high) {
    if (low > high) return NULL;
    int pos = -1;
    int minW = MAXINT;
    for (int i = low; i <= high; i++) {
        if (w[inOrder[i]] < minW) {
            pos = i;
            minW = w[inOrder[i]];
        }
    }
    BiNode<T> *p = new BiNode<T>(inOrder[pos]);
    p->lchild = CreateTree_Use_Pre_In_Order(inOrder, w, low, pos - 1);
    p->rchild = CreateTree_Use_Pre_In_Order(inOrder, w, pos + 1, high);
    return p;
}
template <class T>
void BiTree<T>::createTree_Use_Post_In_Order(T *postOrder, T *inOrder, int n) {
    map<T, int> w;
    for (int i = 0; i < n; i++) {
        w[postOrder[i]] = i;
    }
    root = CreateTree_Use_Post_In_Order(inOrder, w, 0, n - 1);
}
template <class T>
BiNode<T> *BiTree<T>::CreateTree_Use_Post_In_Order(T *inOrder, map<T, int> &w, int low, int high) {
    if (low > high) return NULL;
    int pos = -1;
    int maxW = MININT;
    for (int i = low; i <= high; i++) {
        if (w[inOrder[i]] > maxW) {
            pos = i;
            maxW = w[inOrder[i]];
        }
    }
    BiNode<T> *p = new BiNode<T>(inOrder[pos]);
    p->lchild = CreateTree_Use_Post_In_Order(inOrder, w, low, pos - 1);
    p->rchild = CreateTree_Use_Post_In_Order(inOrder, w, pos + 1, high);
    return p;
}

template <class T>
void BiTree<T>::createTree_Use_Level_In_Order(T *levelOrder, T *inOrder, int n) {
    map<T, int> w;
    for (int i = 0; i < n; i++) {
        w[levelOrder[i]] = i;
    }
    root = CreateTree_Use_Level_In_Order(inOrder, w, 0, n - 1);
}
template <class T>
BiNode<T> *BiTree<T>::CreateTree_Use_Level_In_Order(T *inOrder, map<T, int> &w, int low, int high) {
    if (low > high) return NULL;
    int pos = -1;
    int minW = MAXINT;
    for (int i = low; i <= high; i++) {
        if (w[inOrder[i]] < minW) {
            pos = i;
            minW = w[inOrder[i]];
        }
    }
    BiNode<T> *p = new BiNode<T>(inOrder[pos]);
    p->lchild = CreateTree_Use_Level_In_Order(inOrder, w, low, pos - 1);
    p->rchild = CreateTree_Use_Level_In_Order(inOrder, w, pos + 1, high);
    return p;
}

#endif