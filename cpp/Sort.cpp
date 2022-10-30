/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: Sort.cpp
 * @filepath: cpp\Sort.cpp
 * @date: 2022-10-26 13:49:13
 * @description:  排序测试
 */
#include "../head/sort.h"

#include <iostream>
using namespace std;

int main() {
    int data[100000];
    int n = 100;
    int random = 2;
    int source[n] = {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0};
    cinRandomIntData(data, n, random);
    // cinIntData(data, source, n);
    printData(data, n);

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
    // mergeSort2(data, n);
    // quickSort2(data, n);

    radixSort(data, n, 10);
    printData(data, n);

    return 0;
}
