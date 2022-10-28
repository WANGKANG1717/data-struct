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
#include <iostream>
using namespace std;

#define lchild(x) ((x)*2 + 1)
#define rchild(x) ((x)*2 + 2)
// 这里的x为堆中最后一个元素的下标
#define parent(x) (((x)-1) / 2)
template <class T>
void printHeap(T data[], int n) {
    cout << "-----------------Heap Print----------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "-----------------Heap Print----------------------" << endl;
}
template <class T>
void adjustHeapTop2Bottom(T data[], int n, int p) {
    T tmp = data[p];
    // giao 这里应该为n-1  堆中最后一个元素的下标
    while (p <= parent(n - 1)) {
        //确定左右子树中最大的一个
        int child = lchild(p);
        // child + 1 < n
        if (child + 1 <= n - 1 && data[child + 1] > data[child]) {
            child++;
        }
        if (tmp > data[child]) break;
        data[p] = data[child];
        p = child;
    }
    data[p] = tmp;
}
/// @brief 从下向上调整堆 插入堆有用
/// @tparam T
/// @param data  //堆
/// @param s   //插入的位置
template <class T>
void adjustHeapBottom2Top(T data[], int s) {
    int tmp = data[s];
    while (s) {
        int parent = parent(s);
        if (tmp < data[parent]) break;
        data[s] = data[parent];
        s = parent;
    }
    data[s] = tmp;
}
///////////////////
template <class T>
void buildHeap(T data[], int n) {
    for (int i = parent(n); i >= 0; i--) {
        adjustHeapTop2Bottom(data, n, i);
    }
}
template <class T>
void heapSort(T data[], int n) {
    // printHeap(data, n);
    buildHeap(data, n);
    cout << 0 << endl;
    // printHeap(data, n);
    for (int i = n - 1; i > 0; i--) {
        T tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        adjustHeapTop2Bottom(data, i, 0);
        //////////////////
        // cout << i << endl;
        // printHeap(data, n);
    }
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

/**
 * @date: 2022-10-28 15:14:14
 * @description: 最后两个算法 归并排序 基数排序
 */
/**
 * @date: 2022-10-28 15:35:01
 * @description: 归并排序异常顺利的写完了！！！
 */
#define mid(x, y) (((x) + (y)) / 2)
//合并函数
//合并之前要做好判断
template <class T>
void merge(T data[], int l, int mid, int r) {
    // l ~ mid   mid+1 ~ r
    int low = l, high = mid + 1, pos = 0;
    T *tmp = new T[r - l + 1];
    while (low <= mid && high <= r) {
        if (data[low] < data[high]) {
            tmp[pos++] = data[low++];
        } else {
            tmp[pos++] = data[high++];
        }
    }
    while (low <= mid) {
        tmp[pos++] = data[low++];
    }
    while (high <= r) {
        tmp[pos++] = data[high++];
    }
    //写回归并好的数据
    for (int i = l, j = 0; i <= r; i++, j++) {
        data[i] = tmp[j];
    }
}
/// @brief 归并排序主函数
/// @tparam T
/// @param data 数组
/// @param l 低下标
/// @param r 高下标
template <class T>
void MergeSort(T data[], int l, int r) {
    if (l >= r) return;
    /// mid 向下取整
    int mid = mid(l, r);
    //先进行小的归并
    MergeSort(data, l, mid);
    MergeSort(data, mid + 1, r);
    merge(data, l, mid, r);
}

/// @brief 归并排序
/// @tparam T
/// @param data
/// @param n 数组中的元素个数
template <class T>
void mergeSort(T data[], int n) {
    MergeSort(data, 0, n - 1);
}

/**
 * @date: 2022-10-28 16:07:40
 * @description: 非递归的归并函数
 *              有点小bug 需要调试一下
 */
template <class T>
void mergeSort2(T data[], int n) {
    // i步长 2, 4, 8, 16...
    int k;
    for (k = 2; k < n; k *= 2) {
        int l, r, mid;
        for (l = 0; l <= n - k; l += k) {
            r = l + k - 1;
            mid = mid(l, r);
            merge(data, l, mid, r);
        }
        //最后可能还剩一小块，需要单独合并
        if (l <= n - 1) {
            r = n - 1;
            int mid = mid(l, r);
            merge(data, l, mid, r);
        }
    }
    k /= 2;
    merge(data, 0, k - 1, n - 1);
}
