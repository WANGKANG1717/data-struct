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
    for (int i = 0; i < 1000; i++) {
        data[i] = rand() % 10;
    }
    // int data[10] = {5, 3, 1, 6, 9, 0, 8, 7, 2, 4};

    // insertSort(data, 10);
    // binaryInsertSort(data, 10);
    // shellSort(data, 1000);
    // selectSort(data, 1000);
    quickSort(data, 1000);

    for (int i = 0; i < 1000; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
