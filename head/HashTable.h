/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: HashTable.h
 * @filepath: head\HashTable.h
 * @date: 2022-10-24 18:31:03
 * @description: 哈希表头文件
 */

#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include <iostream>
using namespace std;
/// @brief 使用除留余数法解决冲突
class Node {
   public:
    int key;    ///键值
    int value;  ///键值对应的数据
    /**
     * @date: 2022-10-25 13:21:52
     * @description: deleteTag==true  此节点数据别删除 此时不用管 tag
     *               deleteTag==false && tag==true 此节点存在数据
     *               deleteTag==false && tag==false 此节点不存在数据
     */
    bool tag;        //是否存在数据
    bool deleteTag;  //此节点是否被删除
    Node() : value(-1), key(-1), tag(false), deleteTag(false){};
    Node(int key, int value) : key(key), value(value), tag(true), deleteTag(false){};
    ~Node(){};
    friend ostream &operator<<(ostream &out, const Node &a) {
        out << "value:" << a.value << " key:" << a.key << " tag:" << a.tag << " deleteTag:" << a.deleteTag;
        return out;
    }
};
class HashTable {
    static const int MAXSIZE = 100;

   private:
    Node *data;
    int len;  //哈希表长
    int M;
    double alpha;  //装载因子
    int cnt;       //哈希表中的已经插入的数据个数
    int calculate_M(int M);
    bool isPrime(int num);
    bool Insert(int key, int x);

   public:
    HashTable(int len = MAXSIZE);
    ~HashTable();
    int getKey(int x);  //通过除留余数法得到键值
    bool insert(int x);
    int solveConflict1(int key);  //线性探测法
    Node search(int x);
    bool remove(int x);
    void clear();
    int getM();
    int getLen();
    double getAlpha();
    bool isEmpty(int key);
    bool deleteNode(int key);
    void print();
    void init();
};
int HashTable::calculate_M(int len) {
    int M = len;
    while (M) {
        if (isPrime(M)) break;
        M--;
    }
    return M;
}

bool HashTable::isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

HashTable::HashTable(int len) {
    if (len <= 0) {
        cout << "Error: len should bigger than 0!" << endl;
        exit(0);
    }
    this->cnt = 0;
    this->alpha = 0;
    this->len = len;
    this->data = new Node[len]();
    this->M = calculate_M(len);
    init();
}

HashTable::~HashTable() {
    cout << "~HashTable" << endl;
    delete[] data;
}

int HashTable::getKey(int x) {
    return x % M;
}
int HashTable::solveConflict1(int key) {
    return (key + 1) % len;
}
/// @brief 插入散列空间
/// @param x 为要插入的值
/// @return
bool HashTable::insert(int x) {
    int key = getKey(x);
    if (isEmpty(key)) {
        return Insert(key, x);
    }
    //线性探测法解决冲突
    int p = key;
    do {
        p = solveConflict1(p);
        if (isEmpty(p)) {
            return Insert(p, x);
        }
        //哈希表中不允许插入相同的键值
        else if (!isEmpty(p) && data[p].value == x) {
            cout << "same Key!";
            return false;
        }
    } while (p != key);
    cout << "插入失败" << endl;
    return false;
}
/// @brief 在散列空间中查找x
/// @param x 要查找的键值
/// @return
Node HashTable::search(int x) {
    int key = getKey(x);
    if (!isEmpty(key) && data[key].value == x) {
        return data[key];
    } else if (isEmpty(key)) {
        Insert(key, x);
        return data[key];
    }
    int p = key;
    do {
        p = solveConflict1(p);
        if (!isEmpty(p) && data[p].value == x) {
            return data[p];
        } else if (isEmpty(p)) {
            //说明哈希表中没有 进行插入操作
            Insert(p, x);
            return data[p];
        }
    } while (p != key);
    cout << "Not Found2!" << endl;
    return Node();
}

bool HashTable::remove(int x) {
    Node p = search(x);
    //说明查找成功，可以删除
    return deleteNode(p.key);
}

void HashTable::clear() {
    cout << "Clear!" << endl;
    //不需要物理删除
    for (int i = 0; i < len; i++) {
        data[i].deleteTag = true;
        data[i].tag = false;
    }
    cnt = 0;
}

int HashTable::getM() {
    return M;
}
int HashTable::getLen() {
    return len;
}
double HashTable::getAlpha() {
    return cnt * 1.0 / len;
}

bool HashTable::isEmpty(int key) {
    if (data[key].deleteTag == false && data[key].tag == true) {
        return false;
    } else
        return true;  // deleteTag=true || (tag=false && deleteTag=false)
}
bool HashTable::deleteNode(int key) {
    if (!isEmpty(key)) {
        data[key].deleteTag = true;
        cnt--;
        return true;
    } else {
        return false;
    }
}
void HashTable::print() {
    cout << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < len; i++) {
        cout << data[i] << endl;
    }
    cout << "--------------" << endl;
    cout << endl;
}

void HashTable::init() {
    for (int i = 0; i < len; i++) {
        data[i].key = i;
        data[i].value = -1;
    }
}
bool HashTable::Insert(int key, int x) {
    data[key] = Node(key, x);
    cnt++;
    return true;
}

#endif
