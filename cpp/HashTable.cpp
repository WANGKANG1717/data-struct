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
    HashTable h(100);
    debug(h.getLen());
    debug(h.getM());
    debug(h.getAlpha());
    for (int i = 0; i < 103; i++) {
        bool flag = h.insert(i);
        if (flag) {
            cout << "插入成功" << i << endl;
        } else {
            cout << "插入失败" << i << endl;
        }
    }
    debug(h.getLen());
    debug(h.getM());
    debug(h.getAlpha());
    return 0;
}
