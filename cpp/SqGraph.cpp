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
#define cio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define _T     \
    int _T;    \
    cin >> _T; \
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
#include "../head/SqGraph.h"

int main() {
    cio;
    SqGraph G(5);
    // G.print();
    G.setEdge(0, 1, 1);
    G.setEdge(1, 2, 2);
    G.setEdge(1, 4, 3);
    G.setEdge(4, 3, 1);
    // G.setEdge(2, 4, 3);
    // G.print();
    //
    // debug(G.edgeNum());
    // debug(G.getWeight(0));
    // debug(G.getWeight(1));
    // debug(G.getWeight(2));
    // debug(G.getWeight(3));
    // debug(G.getWeight(4));

    // G.dfs(0);
    // cout << endl;
    // G.dfs(1);
    // cout << endl;
    // G.dfs(2);
    // cout << endl;
    // G.dfs(3);
    // cout << endl;
    // G.dfs(4);
    // cout << endl;

    //

    // G.bfs(0);
    // cout << endl;
    // G.bfs(1);
    // cout << endl;

    // G.bfs(2);
    // cout << endl;

    // G.bfs(3);
    // cout << endl;

    // G.bfs(4);
    // cout << endl;

    return 0;
}