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
    int data[10] = {5, 3, 1, 6, 9, 0, 8, 7, 2, 4};
    // InsertSort(data, 10);
    BinaryInsertSort(data, 10);

    for (int i = 0; i < 10; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
