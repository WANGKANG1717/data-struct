#include "SqList.h"
#include "CustomException.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) { return a < b; }

bool cmp2(int a, int b) { return a > b; }

int main() {
    SqList<int> sqlist(10);
    for (int i = 0; i < 10; i++) {
        sqlist.setData(10 - i, i);
    }

    cout << "sqlist" << endl;
    sqlist.print();

    try {
        sqlist.bubbleSort(0, 9, cmp);
        sqlist.print();
        sqlist.reverse(0, 5);
        sqlist.print();
           sqlist.reverse(6, 9);
        sqlist.print();
            sqlist.reverse(0, 9);
        sqlist.print();
        sqlist._delete(4);
        sqlist.print();
        // int index = sqlist.binarySearch(0, 9, 10);
        // int index2=sqlist.search(3, 1, 4);
        // cout << index<<endl;
        // cout << index2<<endl;

        // throw OutOfRange();
    } catch (exception &e) {
        // cout<<"daasd"<<endl;
        cout << e.what() << endl;
    }
    // sqlist.bubbleSort(0, 9, cmp);
    // sqlist.print();

    // sqlist.bubbleSort(0, 9, cmp2);
    // sqlist.print();

    // sqlist.insert(30, 199);
    // sqlist.print();

    // cout << "sqlist2" << endl;
    // SqList<int> s2=sqlist;
    // s2.print();

    // try
    // {
    //     throw OutOfRange(19,1,1);
    // }
    // catch(exception& e)
    // {
    //     cout<< e.what() << '\n';
    // }

    // SqList<char> s(sqlist);
    // s.printData();

    return 0;
}
