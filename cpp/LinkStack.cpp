#include "../head/LinkStack.h"
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

int main() {
    cio;
    LinkStack<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    cout << s.getLength() << endl;
    s.clear();
    // while (!s.isEmpty()) {
    //     cout << s.getTop() << endl;
    //     s.pop();
    // }
    s.pop();

    return 0;
}