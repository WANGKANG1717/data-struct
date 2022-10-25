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
    int key;         ///键值
    int value;       ///键值对应的数据
    bool tag;        //是否存在数据
    bool deleteTag;  //此节点是否被删除
    Node() : tag(false), deleteTag(false){};
    Node(int key, int value) : key(key), value(value), tag(true), deleteTag(false){};
    ~Node(){};
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
}

HashTable::~HashTable() {
    cout << "~HashTable" << endl;
    delete[] data;
}

int HashTable::getKey(int x) {
    return x % M;
}
int HashTable::solveConflict1(int key) {
    return key + 1;
}
/// @brief 插入散列空间
/// @param x 为要插入的值
/// @return
bool HashTable::insert(int x) {
    int key = getKey(x);
    if (data[key].tag == false) {
        data[key] = Node(key, x);
        cnt++;
        return true;
    }
    //线性探测法解决冲突
    int p = key;
    do {
        p = solveConflict1(p);
        if (data[p].tag == false) {
            data[p] = Node(p, x);
            cnt++;
            return true;
        }
        //哈希表中不允许插入相同的键值
        else if (data[key].tag == true && data[key].value == x) {
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
    if (data[key].tag == true && data[key].value == x) {
        return data[key];
    }
    int p = key;
    do {
        p = solveConflict1(p);
        //没有删除 存在值 值为x 唯一确定一个Node节点
        if (data[key].deleteTag == false && data[key].tag == true && data[key].value == x) {
            return data[p];
        } else if (data[key].tag == false) {
            //说明此节点虽然没有值，但是之前被删除了
            if (data[key].deleteTag == true) {
                continue;
            }
            cout << "查找失败2" << endl;
            return Node();
            //其他情况：有值，但是和x不一样
        }
    } while (p != key);
    cout << "查找失败" << endl;
    return Node();
}

bool HashTable::remove(int x) {
    Node p = search(x);
    //说明查找成功，可以删除
    if (p.tag == true && p.value == x) {
        data[p.key].deleteTag = true;  //删除操作只需要将删除标记改一下即可
        cnt--;
        return true;
    } else
        return false;
}

void HashTable::clear() {
    cout << "Clear!" << endl;
    delete[] data;
    data = new Node[len];
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

#endif
