#include "../head/LinkList.h"
#include <iostream>
using namespace std;
#define debug(x) cout << "x = " << x << endl
int main() {
    LinkList<int> link;
    int a[10] = {1, 2, 3, 4, 5, 6, 4, 3, 1, 1};
    link.create(a, 10);
    // cout<<link.isEmpty()<<endl;
    // link.print();
    try {
        int b = 10;
        cout << link.getData(5, b) << endl;
        debug(b);
        LinkNode<int> *p = link.Locate(6);
        if (p == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << p->data << endl;
            cout << p->next->data << endl;
        }
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << "°¡´ó´ó";

    return 0;
}