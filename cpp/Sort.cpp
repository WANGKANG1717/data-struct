/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: Sort.cpp
 * @filepath: cpp\Sort.cpp
 * @date: 2022-10-26 13:49:13
 * @description:  排序测试
 */
#include "../head/sort.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand((int)time(NULL));
    int data[100000];
    int n = 1000;
    int random = 2;
    // int data[] = {1, 8, 9, 1, 2};
    for (int i = 0; i < n; i++) {
        data[i] = rand() % random;
    }

    // insertSort(data, 10);
    // binaryInsertSort(data, 10);
    // shellSort(data, 1000);
    // selectSort(data, 1000);
    // quickSort(data, 1000);
    // bubbleSort(data, 10000);
    // heapSort(data, n);    //调了好久才调出来
    // for (int i = 0; i < n; i++) {
    //     int x = rand() % 10;
    //     data[i] = x;
    //     adjustHeapBottom2Top(data, i);
    // }

    // mergeSort(data, n);
    mergeSort2(data, n);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
