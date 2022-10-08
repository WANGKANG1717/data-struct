/*
 * @Author: WANGKANG 1686617586@qq.com
 * @Date: 2022-10-04 18:43:53
 * @LastEditors: WANGKANG 1686617586@qq.com
 * @LastEditTime: 2022-10-08 13:13:45
 * @FilePath: \cppfile\cpp\SqList.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../head/Sqlist.h"
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
