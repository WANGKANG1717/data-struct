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
#include "../head/String.h"

int main() {
    cio;
    char tmp[11] = "1234567890";
    String s(tmp);
    cout << s.getSize() << endl;
    // s << cout;
    cout << s << endl;
    // cin>>s;
    // cout<<s<<endl;
    String p(s);
    debug(p.getSize());
    debug(p);

    char tmp2[11] = "9087654321";
    String f = (tmp2);
    debug((p == s));
    debug((p == f));
    debug(f);
    debug((p != s));
    debug((f != s));
    String e;
    debug(!e);
    debug(!f);
    debug((f < p));
    debug((f > p));
    debug((f < e));
    debug((f > e));
    debug((s < p));
    debug((s > p));

    // f=p;
    // debug(f);
    p=f;
    debug(p);

    return 0;
}