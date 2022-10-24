/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: Btree.h
 * @filepath: head\Btree.h
 * @date: 2022-10-23 14:44:11
 * @description: 终于还是对B树动手了
 */
/**
 * @date: 2022-10-23 14:44:57
 * @description: 为了简化实现，不使用模板
 */

/**
 * @date: 2022-10-24 18:25:34
 * @description: 虽然我有信心有能力，可以把B树和B+树的算法搞出来
 *              但是，我感觉现在这并非主要矛盾，我恐怕又犯了理想主义的错误，因此我决定，暂时放弃这两个数据结构的实现
 */

#ifndef __BTREE_H__
#define __BTREE_H__
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
/**
 * @date: 2022-10-23 16:09:07
 * @description: 最后还是得自己写啊
 *              看网上的太麻烦了，实际上没有动脑子，还是得自己实现才行
 *              主要是得明白原理
 */
class Node {
   public:
    bool isLeaf;    //是否叶子节点
    int keyNum;     //节点包含的关键字数量
    int *keys;      //关键字数组                //这里的0号都有使用，毕竟为了节省空间吗！
    Node **childs;  //孩子数组
    Node(const int KEY_MAX) {
        keys = new int[KEY_MAX];
        childs = new Node *[KEY_MAX]();
        keyNum = 0;
        isLeaf = false;  //默认为叶子节点
    }
    ~Node() {
        delete[] keys;
        delete[] childs;
    }
};
class Result {
   public:
    int i;     // 在结点中的关键字位序
    bool tag;  // 是否找到了 true 找到
    Node *p;   // 关键字所在的节点
   public:
    Result(int i, int tag, Node *p) : i(i), tag(tag), p(p){};
    ~Result(){};
};
class BTree {
   private:
    int M;        // M叉B树
    int KEY_MAX;  //一个节点中最大键值数
    int KEY_MIN;  //一个节点中的最小键值数
    Node *root;   //根节点
    //取中间值(向上取整)
    int MID(int x) {
        // return x % 2 == 0 ? (x / 2) : (x / 2 + 1);
        return (x + 1) / 2;
    }

   public:
    BTree(int M = 2);  //默认为二叉B树
    ~BTree();
    bool contain(int key);    //搜索关键字 存在返回true 否则返回false
    bool insert(int key);     //插入关键字
    bool remove(int key);     //移除关键字
    void print();             //打印B数
    void clear();             //清空B树
    Result &search(int key);  //在B树中查找关键字

   private:
    bool Contain(Node *p, int key);
    void Clear(Node *&p);
    void Print(Node *p);
    int SearchInNode(Node *p, int key);  //在节点中找第一不比key小的序号 如果p为NULL返回-1
    Result &SearchInTree(Node *p, int key);
};
BTree::BTree(int M) {
    this->M = M;
    this->KEY_MAX = M - 1;
    this->KEY_MIN = MID(M) - 1;
    root = NULL;  //  置为空树
}

BTree::~BTree() {
}

bool BTree::contain(int key) {
    return Contain(root, key);
}
bool BTree::Contain(Node *p, int key) {
    if (p == NULL) return false;
    for (int i = 0; i < p->keyNum; i++) {
        if (p->keys[i] == key) {
            return true;
        } else if (key > p->keys[i]) {
            return Contain(p->childs[i + 1], key);
        }
    }
}
void BTree::clear() {
    Clear(root);
}
void BTree::Clear(Node *&p) {
    if (p == NULL)
        return;
    else {
        for (int i = 0; i <= p->keyNum; i++) {
            Clear(p->childs[i]);
        }
        delete p;
    }
}
void BTree::print() {
    Print(root);
}
void BTree::Print(Node *p) {
    if (p == NULL)
        return;
    else {
        cout << "<";
        for (int i = 0; i < p->keyNum; i++) {
            Print(p->childs[i]);
            cout << p->keys[i] << " ";
        }
        cout << ">";
    }
}
int BTree::SearchInNode(Node *p, int key) {
    if (p == NULL) return -1;
    int i = 0;
    for (i; i < p->keyNum; i++) {
        if (p->keys[i] >= key) break;
    }
    return i;
}
Result &BTree::search(int key) {
    return SearchInTree(root, key);
}
/**
 * @date: 2022-10-24 17:27:30
 * @description: 突然发现如果不使用递归的话，可以不用写这个函数了，但是为了保持一致，还是写吧
 */
/// @brief 不使用递归进行查找
/// @param p 根节点
/// @param key 要查找的关键字
/// @return 结果类型
Result &BTree::SearchInTree(Node *p, int key) {
    bool found = false;
    Node *parent = NULL;
    int i = -1;
    while (!p && !found) {
        i = SearchInNode(p, key);
        if (i < p->keyNum && p->keys[i] == key)
            found = true;
        else {
            parent = p;
            p = p->childs[i];
        }
    }
    if (found) {
        Result result(i, true, p);
        return result;
    } else {
        Result result(i, false, parent);  //说明当前节点为空的
        return result;
    }
}

#endif
