#include "SqList.h"
#include <iostream>
#include "CustomException.h"
#include <algorithm>
using namespace std;



int main() {
    SqList<int> sqlist(10);
    for (int i = 0; i < 10; i++) {
        sqlist.setData(i, i);
    }
    cout << "sqlist" << endl;
    sqlist.print();

    cout << "sqlist2" << endl;
    SqList<int> s2=sqlist;
    s2.print();

    try
    {
        throw OutOfRange(19,1,1);
    }
    catch(exception& e)
    {
        cout<< e.what() << '\n';
    }

    
    

    // SqList<char> s(sqlist);
    // s.printData();

    return 0;
}
