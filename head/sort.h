/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: sort.h
 * @filepath: head\sort.h
 * @date: 2022-10-26 13:36:50
 * @description:  排序
 */

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
 * @date: 2022-10-26 14:03:26
 * @description: 嘎嘎嘎，写的就是这么骚气！！
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
