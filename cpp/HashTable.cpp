/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: HashTable.cpp
 * @filepath: cpp\HashTable.cpp
 * @date: 2022-10-24 18:28:42
 * @description:  哈希表的实现
 */

#include "../head/HashTable.h"

#include <iostream>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
/**
 * @date: 2022-10-24 19:30:21
 * @description: 插入函数有点问题，需要修改
 */
int main() {
    HashTable h(10);
    debug(h.getLen());
    debug(h.getM());
    debug(h.getAlpha());
    int x[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
    for (int i = 0; i < 13; i++) {
        bool flag = h.insert(x[i]);
        if (flag) {
            cout << "插入成功" << x[i] << endl;
        } else {
            cout << "插入失败" << x[i] << endl;
        }
    }
    debug(h.getLen());
    debug(h.getM());
    debug(h.getAlpha());
    return 0;
}
