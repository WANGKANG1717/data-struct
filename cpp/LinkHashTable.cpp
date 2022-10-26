/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: LinkHashTable.cpp
 * @filepath: cpp\LinkHashTable.cpp
 * @date: 2022-10-25 16:00:28
 * @description: 链哈希
 */

#include "../head/LinkHashTable.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
    LinkHashTable l(13);
    for (int i = 0; i < 50; i++) {
        l.insert(i);
    }

    l.print();
    srand((int)(time(NULL)));
    for (int i = 0; i < 50; i++) {
        int random = rand() % 100;
        cout << random << " ";
        Node *p = l.search(random);
        if (p)
            cout << *p << endl;
        else
            cout << "NULL" << endl;
    }
    // for (int i = 0; i < 10; i++) {
    //     l.remove(i);
    // }
    // l.print();

    // l.clear();
    // l.print();

    return 0;
}
