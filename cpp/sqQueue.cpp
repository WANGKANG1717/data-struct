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
#include "../head/SqQueue.h"

int main() {
    cio;

    SqQueue<int> s(10);
    cout << s.getLength() << endl;
    for (int i = 0; i < 10; i++) {
        s.EnQueue(i);
        cout << s.getLength() << endl;
    }
    s.print();
    int x;
    s.DeQueue(x);
    s.DeQueue(x);
    s.DeQueue(x);
    cout << s.getFront() << endl;
    cout << s.getRear() << endl;
    s.EnQueue(10000);
    s.EnQueue(1000022);
    s.EnQueue(101212210);
    cout << s.getRear() << endl;
    // for (int i = 0; i < 10; i++) {
    //     s.DeQueue(x);
    // }
    s.clear();
    cout<<s.getLength();

    return 0;
}