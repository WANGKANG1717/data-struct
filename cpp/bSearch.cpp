/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: Search.cpp
 * @filepath: cpp\Search.cpp
 * @date: 2022-10-19 14:32:54
 * @description: 查找相关的算法实现
 */
/**
 * @date: 2022-10-19 14:34:14
 * @description: 今天就先开个头，顺序查找太简单了略去不表
 */
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
int Data[15] = {20, 24, 50, 57, 87, 94, 96,
                67, 14, 66, 95, 82, 42, 31, 26};
int n = 15;
int bSearch(int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (Data[mid] == x) {
            return mid;
        } else if (Data[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    // int data[15];
    // srand((int)(time(NULL)));
    // for (int i = 0; i < 15; i++) {
    //     data[i] = rand() % 100;
    // }

    sort(Data, Data + n);
    //
    cout << "数据集" << endl;
    for (int i = 0; i < 15; i++) {
        cout << Data[i] << ",";
    }
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << data[i] << " ";
    // }
    // cout << endl;
    int x;
    cout << "请输入你要查找的数据(以-1为结束)" << endl;
    while (cin >> x && x != -1) {
        cout << bSearch(x) << endl;
    }

    return 0;
}