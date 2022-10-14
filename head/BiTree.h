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
#include "../head/LinkQueue.h"
#include "../head/LinkStack.h"
#include <iostream>
#include <map>
using namespace std;
template <class T> class BiNode {
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

template <class T> class BiTree : public BiNode<T> {
  private:
    BiNode<T> *root;

    BiNode<T> *getParent(BiNode<T> *curr, BiNode<T> *pre, BiNode<T> *target);
    BiNode<T> *getLeftSibing(BiNode<T> *curr, BiNode<T> *target);
    BiNode<T> *getRightSibing(BiNode<T> *curr, BiNode<T> *target);

  public:
    BiTree();  //
    ~BiTree(); ////
    void clear();
    void Clear(BiNode<T> *&Root); //
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
    void create(BiNode<T> *&Root, T *data, T endFlag, int &i, int n); //
    /**
     * @date: 2022-10-13 13:28:50
     * @param: root
     * @return: NULL
     * @description: 根据提示按照前序序列创建二叉树
     */
    void create(T endFlag);                 //
    BiNode<T> *Create(T endFlag);           //
    bool isEmpty();                         //
    int getDepth();                         //
    int GetDepth(BiNode<T> *Root, int dep); //
    BiNode<T> *&getRoot();                  //
    BiNode<T> *parent(BiNode<T> *target);
    BiNode<T> *LeftSibing(BiNode<T> *target);
    BiNode<T> *RightSibing(BiNode<T> *target);
    BiNode<T> *Lchild(BiNode<T> *curr);
    BiNode<T> *Rchild(BiNode<T> *curr);
    void preOrder(BiNode<T> *Root);  //
    void preOrder2();                //
    void inOrder(BiNode<T> *Root);   //
    void inOrder2();                 //
    void postOrder(BiNode<T> *Root); //
    void postOrder2();
    void levelOrder(); //
};
template <class T> BiTree<T>::BiTree() : root(NULL) {}

template <class T> BiTree<T>::~BiTree() { Clear(root); }

template <class T> void BiTree<T>::clear() {
    if (root == NULL)
        return;
    Clear(root);
    root = NULL;
}

template <class T> void BiTree<T>::Clear(BiNode<T> *&r) {
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
template <class T> void BiTree<T>::create(T endFlag) { root = Create(endFlag); }
template <class T> BiNode<T> *BiTree<T>::Create(T endFlag) {
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

template <class T> bool BiTree<T>::isEmpty() {
    if (root == NULL) {
        return true;
    } else
        return false;
}
template <class T> int BiTree<T>::getDepth() { return GetDepth(root, 0); }
template <class T> int BiTree<T>::GetDepth(BiNode<T> *Root, int dep) {
    if (Root == NULL)
        return 0;
    int ldep = GetDepth(Root->lchild, dep + 1);
    int rdep = GetDepth(Root->rchild, dep + 1);
    return max(ldep, rdep) + 1;
}

template <class T> BiNode<T> *&BiTree<T>::getRoot() { return root; }

template <class T> BiNode<T> *BiTree<T>::parent(BiNode<T> *target) {
    return getParent(root, NULL, target);
}
template <class T> BiNode<T> *BiTree<T>::LeftSibing(BiNode<T> *target) {
    return getLeftSibing(root, NULL, target);
}

template <class T> BiNode<T> *BiTree<T>::RightSibing(BiNode<T> *target) {
    return getRightSibing(root, NULL, target);
}
//
template <class T>
BiNode<T> *BiTree<T>::getParent(BiNode<T> *curr, BiNode<T> *pre,
                                BiNode<T> *target) {
    if (curr == NULL)
        return NULL;
    if (curr == target) {
        return pre;
    }
    return getParent(curr->lchild, curr, target) |
           getParent(curr->rchild, curr, target);
}
template <class T>
BiNode<T> *BiTree<T>::getLeftSibing(BiNode<T> *curr, BiNode<T> *target) {
    if (curr == NULL)
        return NULL;
    if (curr->rchild == target) {
        return curr->lchild;
    }
    return getLeftSibling(curr->lchild, target) |
           getLeftSibling(curr->rchild, target);
}
template <class T>
BiNode<T> *BiTree<T>::getRightSibing(BiNode<T> *curr, BiNode<T> *target) {
    if (curr == NULL)
        return NULL;
    if (curr->lchild == target) {
        return curr->rchild;
    }
    return getLeftSibling(curr->lchild, target) |
           getLeftSibling(curr->rchild, target);
}
//
template <class T> BiNode<T> *BiTree<T>::Lchild(BiNode<T> *curr) {
    if (curr == NULL)
        return NULL;
    return curr->lchild;
}

template <class T> BiNode<T> *BiTree<T>::Rchild(BiNode<T> *curr) {
    if (curr == NULL)
        return NULL;
    return curr->rchild;
}

template <class T> void BiTree<T>::preOrder(BiNode<T> *Root) {
    if (Root) {
        cout << Root->data << " ";
        preOrder(Root->lchild);
        preOrder(Root->rchild);
    }
}
template <class T> void BiTree<T>::preOrder2() {
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

template <class T> void BiTree<T>::inOrder(BiNode<T> *Root) {
    if (Root) {
        inOrder(Root->lchild);
        cout << Root->data << " ";
        inOrder(Root->rchild);
    }
}
template <class T> void BiTree<T>::inOrder2() {
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

template <class T> void BiTree<T>::postOrder(BiNode<T> *Root) {
    if (Root) {
        postOrder(Root->lchild);
        postOrder(Root->rchild);
        cout << Root->data << " ";
    }
}
template <class T> void BiTree<T>::postOrder2() {
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
                p = NULL; //神来之笔
            } else {
                p = p->rchild;
            }
        }
    }
}
template <class T> void BiTree<T>::levelOrder() {
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

#endif