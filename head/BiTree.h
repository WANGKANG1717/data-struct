/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BiTree.h
 * @filepath: head\BiTree.h
 * @date: 2022-10-13 13:00:50
 * @description: 树
 */

#ifndef __BITREE_H__
#define __BITREE_H__
#include "../head/LinkQueue.h"
#include "../head/LinkStack.h"
#include <iostream>
using namespace std;
template <class T> class BiNode {
  public:
    T data;
    BiNode<T> *lchild, *rchild;
    BiNode() : lchild(NULL), rchild(NULL) {}
    BiNode(T data, BiNode<T> *lchild = NULL, BiNode<T> *rchild = NULL)
        : data(data), lchild(lchild), rchild(rchild) {}
    ~BiNode();
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
    BiTree();
    ~BiTree();
    void clear(BiNode<T> *Root);
    /**
     * @date: 2022-10-13 13:27:03
     * @param: data; i:下标; n: 总的数据大小; endFlag 自定义的结束标志
     * @return: NULL
     * @description: 传一个大小为n的数组，要求前序遍历存储，以#结尾，作为空节点
     */
    void create(BiNode<T> *Root, T *data, T endFlag, int &i, int n);
    /**
     * @date: 2022-10-13 13:28:50
     * @param: root
     * @return: NULL
     * @description: 根据提示按照前序序列创建二叉树
     */
    void create(BiNode<T> *Root, T endFlag);
    bool isEmpty();
    int getDepth(int dep);
    BiNode<T> *getRoot();
    BiNode<T> *parent(BiNode<T> *target);
    BiNode<T> *LeftSibing(BiNode<T> *target);
    BiNode<T> *RightSibing(BiNode<T> *target);
    BiNode<T> *Lchild(BiNode<T> *curr);
    BiNode<T> *Rchild(BiNode<T> *curr);
    void preOrder(BiNode<T> *Root);
    void preOrder2();
    void inOrder(BiNode<T> *Root);
    void inOrder2();
    void postOrder(BiNode<T> *Root);
    void postOrder2();
    void levelOrder();
};
template <class T> BiTree<T>::BiTree() : root(NULL) {}

template <class T> BiTree<T>::~BiTree() { clear(root); }

template <class T> void BiTree<T>::clear(BiNode<T> *Root) {
    // if (isEmpty())
    //     return;
    // clear(root->lchild);
    // clear(root->rchild);
    // delete (root);
}

template <class T>
void BiTree<T>::create(BiNode<T> *Root, T *data, T endFlag, int &i, int n) {
    if (data[i] != endFlag) {
        Root = new BiNode<T>(data[i]);
        i++;
        create(Root->lchild, data, endFlag, i, n);
        create(Root->rchild, data, endFlag, i, n);
    } else {
        Root = NULL;
    }
}
template <class T> void BiTree<T>::create(BiNode<T> *Root, T endFlag) {
    T x;
    cin >> x;
    if (x != endFlag) {
        Root = new BiNode<T>(x);
        create(Root->lchild, endFlag);
        create(Root->rchild, endFlag);
    } else {
        Root = NULL;
    }
}

template <class T> bool BiTree<T>::isEmpty() {
    if (root == NULL) {
        return true;
    } else
        return false;
}

template <class T> int BiTree<T>::getDepth(int dep) {
    if (root == NULL)
        return 0;
    int ldep = getDepth(root->lchild);
    int rdep = getDepth(root->child);
    return max(ldep, rdep) + 1;
}

template <class T> BiNode<T> *BiTree<T>::getRoot() { return root; }

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
        cout << Root->data << endl;
        preOrder(Root->lchild);
        preOrder(Root->rchild);
    }
}
template <class T> void BiTree<T>::preOrder2() {
    cout << "---------------------" << endl;
    cout << "preOrder2:" << endl;
    LinkStack<BiNode<T> *> S;
    BiNode<T> *p = NULL;
    if (!isEmpty()) {
        S.push(root);
        p = root;
        cout << p->data << " ";
    }
    while (!S.isEmpty() || p) {
        while (p->lchild) {
            S.push(p->lchild);
            p = p->lchild;
            cout << p->data << " ";
        }
        p = S.getTop();
        S.pop();
        p = p->rchild;
    }

    cout << "\n---------------------" << endl;
}

template <class T> void BiTree<T>::inOrder(BiNode<T> *Root) {
    if (Root) {
        preOrder(Root->lchild);
        cout << Root->data << endl;
        preOrder(Root->rchild);
    }
}
template <class T> void BiTree<T>::inOrder2() {
    cout << "---------------------" << endl;
    cout << "InOrder2:" << endl;
    LinkStack<BiNode<T> *> S;
    BiNode<T> *p = NULL;
    if (!isEmpty()) {
        S.push(root);
        p = root;
    }
    while (!S.isEmpty() || p) {
        while (p->lchild) {
            S.push(p->lchild);
            p = p->lchild;
        }
        p = S.getTop();
        S.pop();
        cout << p->data << " ";
        p = p->rchild;
    }

    cout << "\n---------------------" << endl;
}

template <class T> void BiTree<T>::postOrder(BiNode<T> *Root) {
    if (Root) {
        preOrder(Root->lchild);
        preOrder(Root->rchild);
        cout << Root->data << endl;
    }
}
template <class T> void BiTree<T>::postOrder2() {}
template <class T> void BiTree<T>::levelOrder() {
    cout << "---------------------" << endl;
    cout << "LevelOrder:" << endl;
    LinkQueue<BiNode<T> *> Q;
    if (root != NULL) {
        Q.EnQueue(root);
    }
    while (!Q.isEmpty()) {
        BiNode<T> *p = Q.front();
        Q.DeQueue();
        cout << p->data << " ";
        if (p->lchild) {
            Q.EnQueue(p->lchild);
        }
        if (p->rchild) {
            Q.EnQueue(p->rchild);
        }
    }
    cout << "\n-----------------------\n";
}

#endif