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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
using namespace std;
#define debug1(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl
/**
 * @date: 2022-10-29 14:16:10
 * @description: 随机输入函数
 */
void cinRandomIntData(int data[], int n, int random) {
    srand((int)time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % random;
    }
}
void cinIntData(int data[], int source[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = source[i];
    }
}
/**
 * @date: 2022-10-29 14:15:29
 * @description: 打印函数
 */
template <class T>
void printData(T data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << ", ";
    }
    cout << endl;
}

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
 * @date: 2022-10-29 15:44:41
 * @description: 快速排序的非递归排序
 */
template <class T>
void quickSort2(T data[], int n) {
    cout << "神么！有必要搞嘛！？？？？" << endl;
    cout << "还得使用栈，不搞了不搞了！" << endl;
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
// l 左边界（含） r 右边界（含） mid（含）
template <class T>
void merge(T data[], T tmp[], int l, int mid, int r) {
    // 这里最好做一个越界检查
    if (l >= r || mid < l || mid > r) return;
    // if (l >= r || mid < l || mid > r) {
    //     debug3(l, mid, r);
    //     exit(0);
    // }
    // if (l >= r) return;
    // l ~ mid   mid+1 ~ r
    int low = l, high = mid + 1, pos = 0;
    //频繁的进行申请空间的命令会降低算法的运行速度
    // T *tmp = new T[r - l + 1];
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
void MergeSort(T data[], T tmp[], int l, int r) {
    if (l >= r) return;
    /// mid 向下取整
    int mid = mid(l, r);
    //先进行小的归并
    MergeSort(data, tmp, l, mid);
    MergeSort(data, tmp, mid + 1, r);
    merge(data, tmp, l, mid, r);
}

/// @brief 归并排序
/// @tparam T
/// @param data
/// @param n 数组中的元素个数
template <class T>
void mergeSort(T data[], int n) {
    T *tmp = NULL;
    if (n > 0) {
        tmp = new T[n];
        if (!tmp) {
            cout << "Error: storage space request failed" << endl;
            return;
        }
    } else {
        cout << "Error: n should > 0 !" << endl;
        return;
    }
    MergeSort(data, tmp, 0, n - 1);
    delete[] tmp;
}

/**
 * @date: 2022-10-28 16:07:40
 * @description: 非递归的归并函数
 *              有点小bug 需要调试一下
 */
template <class T>
void mergeSort2(T data[], int n) {
    T *tmp = NULL;
    if (n > 0) {
        tmp = new T[n];
        if (!tmp) {
            cout << "Error: storage space request failed" << endl;
            return;
        }
    } else {
        cout << "Error: n should > 0 !" << endl;
        return;
    }
    // i步长 2, 4, 8, 16...
    int k;
    for (k = 2; k <= n; k *= 2) {
        int l, r, mid;
        for (l = 0; l <= n - k; l += k) {
            r = l + k - 1;
            mid = mid(l, r);
            merge(data, tmp, l, mid, r);
        }
        // debug1(l);
        if (l < n - 1) {
            // debug1(l);
            /**
             * @date: 2022-10-29 15:05:17
             * @description: 这里要十分注意，最后一项要这么归并
             *                 也就是将最后一项与前面的一段归并为一项
             */
            mid = l + k / 2 - 1;
            r = n - 1;
            //这里还得再做一个越界检查
            //否则的话可能会出现越界错误
            // if (mid >= l && mid <= r)
            merge(data, tmp, l, l + k / 2 - 1, n - 1);
        }
        // debug1(k);
        // printData(data, n);
    }
    k /= 2;
    merge(data, tmp, 0, k - 1, n - 1);
    delete[] tmp;
}

/**
 * @date: 2022-10-29 15:51:23
 * @description: 基数排序
 */

// @date: 2022-10-30 14:17:49
// @brief: 没想到基数排序实现起来还挺简单

/// @brief 基数排序
/// @tparam T 数据类型
/// @param data 数据集
/// @param n 大小
/// @param radix 排序基数
template <class T>
int getD(T data[], int n, int radix) {
    T max_ = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max_) max_ = data[i];
    }
    int d = 0;
    while (max_) {
        d++;
        max_ /= radix;
    }
    return d;
}
int power(int radix, int n) {
    return pow(radix, n);
}
template <class T>
void distribute(T data[], int n, int radix, int k, list<T> bucket[]) {
    // @date: 2022-10-30 14:12:14
    // @brief: 再进行分发之前要注意把桶内的元素清空
    for (int i = 0; i < n; i++) {
        int pos = (data[i] / power(radix, k)) % radix;
        bucket[pos].push_back(data[i]);
    }
}
template <class T>
void collect(T data[], int n, int radix, int k, list<T> bucket[]) {
    int cnt = 0;
    for (int i = 0; i < radix; i++) {
        for (auto p = bucket[i].begin(); p != bucket[i].end(); p++) {
            data[cnt++] = *p;
        }
        bucket[i].clear();
    }
}
template <class T>
void radixSort(T data[], int n, int radix) {
    if (n <= 0) return;
    // @date: 2022-10-30 13:43:49
    // @brief: d 为最高位
    int d = getD(data, n, radix);
    debug1(d);
    list<T> bucket[radix];
    for (int k = 0; k < d; k++) {
        distribute(data, n, radix, k, bucket);
        collect(data, n, radix, k, bucket);
    }
}
