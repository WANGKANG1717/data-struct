/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: BiTree.cpp
 * @filepath: cpp\BiTree.cpp
 * @date: 2022-10-13 13:00:42
 * @description: 树
 */
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define cio                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
#define _T                                                                     \
    int _T;                                                                    \
    cin >> _T;                                                                 \
    while (_T--)
#define MAXN 100010
#define MAXINT 0x7f7f7f7f
#define _MAXINT 0x3f3f3f3f
#define debug(x) cout << #x << "=" << x << endl
#define pii pair<int, int>
#define mk make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int mod = 1e9 + 7;
#include "../head/BiTree.h"
int main() {
    cio;
    // data 1 2 4 0 0 5 0 0 3 0 0
    int data[] = {1, 2, 4, 0, 0, 5, 0, 0, 3, 0, 0};
    int data2[] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0};
    //满二叉树
    int data3[] = {1, 2, 4,  8, 0, 0,  9, 0, 0, 5,  10, 0, 0,  11, 0, 0,
                   3, 6, 12, 0, 0, 13, 0, 0, 7, 14, 0,  0, 15, 0,  0};
    int data4[] = {0};
    BiTree<int> T, T2, T3, T4;
    // T.create(0);
    int i = 0;
    int n = 11;
    int endFlag = 0;
    T.create(T.getRoot(), data, endFlag, i, n);
    i = 0;
    T2.create(T2.getRoot(), data2, endFlag, i, n);
    i = 0;
    T3.create(T3.getRoot(), data3, endFlag, i, 31);
    //空树
    i = 0;
    T4.create(T4.getRoot(), data4, endFlag, i, 1);
    debug(T.getDepth());
    debug(T2.getDepth());
    debug(T3.getDepth());
    debug(T4.getDepth());

    // T.preOrder(T.getRoot());
    // cout << endl;
    // T.inOrder(T.getRoot());
    // cout << endl;
    // T.postOrder(T.getRoot());
    // cout << endl;
    // T.preOrder2();
    // cout << endl;
    // T.inOrder2();
    // cout << endl;
    // T.postOrder2();
    // cout << endl;
    // T.levelOrder();
    // T2.levelOrder();
    // T2.postOrder(T2.getRoot());
    // cout << endl;
    // T2.inOrder2();
    // cout << endl;
    // T2.preOrder2();
    // cout << endl;
    // T2.preOrder(T2.getRoot());
    // T.postOrder2();
    // cout << endl;
    // T2.postOrder2();
    // cout << endl;
    // T3.postOrder2();
    // T4.postOrder2();
    // debug(T.isEmpty());
    // T.clear();
    // debug(T.isEmpty());
    //

    return 0;
}