/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: sort.h
 * @filepath: head\sort.h
 * @date: 2022-10-26 13:36:50
 * @description:  排序
 */

/**
 * @date: 2022-10-27 15:52:54
 * @description: 注 此头文件中的函数0下标均被使用
 */
#include <iostream>
using namespace std;
//插入排序 简单插入排序 二分插入排序 希尔排序

/// @brief 默认的排序函数，就是这么骚气！狗头🐶👌🙌👍
/// @tparam T 排序类型
/// @return a<b 正数， a==b 0， a<b 负数
template <class T>
int cmp(T a, T b) {
    return a < b;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @date: 2022-10-26 16:02:39
 * @description: 简单插入排序
 */
template <class T>
void insertSort(T data[], int n, int (*cmp)(T a, T b) = cmp) {
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
void binaryInsertSort(T data[], int n, int (*cmp)(T a, T b) = cmp) {
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

/**
 * @date: 2022-10-27 13:22:32
 * @description: 希尔排序
 */
template <class T>
void shellSort(T data[], int n, int (*cmp)(T a, T b) = cmp) {
    for (int k = n / 2; k >= 1; k /= 2) {
        for (int i = k; i < n; i++) {
            T tmp = data[i];
            int j = i - k;
            for (; j >= 0; j -= k) {
                if (cmp(tmp, data[j]) > 0) {
                    data[j + k] = data[j];
                } else
                    break;
            }
            data[j + k] = tmp;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @date: 2022-10-27 13:45:48
 * @description: 后面的不再使用cmp比较函数，不够直观
 *              使用c++的重载比较号 则总是可行的
 */

//选择排序 简单选择排序 堆排序 树形选择排序

/**
 * @date: 2022-10-27 13:24:39
 * @description: 简单选择排序
 */
template <class T>
void selectSort(T data[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int index = 0;
        for (int j = 1; j <= i; j++) {
            if (data[j] > data[index]) {
                index = j;
            }
        }
        if (index != i) {
            T tmp = data[index];
            data[index] = data[i];
            data[i] = tmp;
        }
    }
}

/**
 * @date: 2022-10-27 15:43:44
 * @description: 堆排序 （非递归 效率更高）
 */
// c++不允许函数嵌套定义
// 堆排序还是相当的优雅的数据结构
// 可惜只能明天解决了
#define lchild(x) ((x)*2 + 1)
#define rchild(x) ((x)*2 + 2)
#define parent(x) (((x)-1) / 2)
template <class T>
void buildHeap(T data, int n) {
    for (int i = parent(n); i >= 0; i--) {
        adjustHeapTop2Bottom(data, n, i);
    }
}
template <class T>
void adjustHeapTop2Bottom(T data, int n, int p) {
    T tmp = data[p];
    int s;
    while (p <= (n - 1)) {
        if (lchild(p) <= n - 1) {
            T lc = data[lchild(p)];
        }
        if (lchild(p) + 1 <= n - 1) {
            T rc = data[rchild(p)];
        }
    }
}
template <class T>
void adjustHeapBottom2Top(T data, int n, int p) {
}
template <class T>
void heapSort(T data, int n) {
}

/////////////////////////////////////////////////////////////////////////////////////////////

// 交换排序 冒泡排序 快速排序

/**
 * @date: 2022-10-27 15:40:16
 * @description: 冒泡排序
 */

template <class T>
void bubbleSort(T data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                T tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

/**
 * @date: 2022-10-27 13:30:17
 * @description: 快速排序
 */

/**
 * @date: 2022-10-27 14:09:47
 * @description: 对比了以前写的代码，越发简洁了
 *                 码力值++     👌🙌👍
 */
template <class T>
void QuickSort(T data[], int l, int r) {
    if (l >= r) return;
    int low = l, high = r;
    T x = data[low];
    while (low < high) {
        /**
         * @date: 2022-10-27 14:06:35
         * @description: 里面的函数仍然要做边界控制， 否则会出错
         */
        while (low < high && data[high] >= x) {
            high--;
        }
        data[low] = data[high];
        while (low < high && data[low] <= x) {
            low++;
        }
        data[high] = data[low];
    }
    data[low] = x;
    QuickSort(data, l, low - 1);
    QuickSort(data, low + 1, r);
}

template <class T>
void quickSort(T data[], int n) {
    QuickSort(data, 0, n - 1);
}
