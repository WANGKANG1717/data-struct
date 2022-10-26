/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: sort.h
 * @filepath: head\sort.h
 * @date: 2022-10-26 13:36:50
 * @description:  排序
 */
#include <iostream>
using namespace std;
//插入排序
/**
 * @date: 2022-10-26 13:40:00
 * @param: data 要排序数据集 n总的数目 func 比较函数
 * @return: NULL
 * @description:
 */

/// @brief 默认的排序函数，就是这么骚气！狗头🐶👌🙌👍
/// @tparam T 排序类型
/// @param a
/// @param b
/// @return a<b 正数， a==b 0， a<b 负数
template <class T>
int cmp(T a, T b) {
    return a < b;
}

/**
 * @date: 2022-10-26 16:02:39
 * @description: 简单插入排序
 */
template <class T>
void InsertSort(T data[], int n, int (*cmp)(T a, T b) = cmp) {
    for (int i = 1; i < n; i++) {
        T tmp = data[i];
        int j = i;
        for (; j > 0; j--) {
            if (cmp(tmp, data[j - 1]) > 0) {
                data[j] = data[j - 1];
            } else
                break;
        }
        data[j] = tmp;
    }
}
/**
 * @date: 2022-10-26 16:02:16
 * @description: 二分插入排序
 */
template <class T>
void BinaryInsertSort(T data[], int n, int (*cmp)(T a, T b) = cmp) {
    for (int i = 1; i < n; i++) {
        int low = 0, high = i - 1;
        T tmp = data[i];
        /**
         * @date: 2022-10-26 16:03:11
         * @description: 这里是<=
         */
        while (low <= high) {
            int mid = (low + high) / 2;
            if (cmp(tmp, data[mid]) > 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i; j > low; j--) {
            data[j] = data[j - 1];
        }
        data[low] = tmp;
        // for (int j = 0; j < i; j++) {
        //     cout << data[j] << " ";
        // }
        // cout << endl;
    }
}
