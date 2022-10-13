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

    char tmp[11] = "1234567891";
    char tmp2[1100] = "121211212";
    String s(tmp);
    String pat(tmp2);

    // s.reverse();
    // debug(s);
    // pat.reverse();
    // debug(pat);

    // debug(s.BF_find(pat));
    // debug(s.KMP_find(pat));
    int next[10];
    int nextVal[10];
    pat.getNext(next);
    for (int i = 0; i < 10; i++) {
        cout << next[i] << " ";
    }
    cout<<endl;
    pat.getNextVal(nextVal);
    for (int i = 0; i < 10; i++) {
        cout << nextVal[i]+1 << " ";
    }

    // cout << endl;
    // debug(s);
    // debug(s.getSize());
    // String p(tmp2);
    // debug(p);
    // debug(p.getSize());
    // String h = p + s;
    // debug(h);
    // String f = h + h;
    // debug(f);
    // debug(f.getSize());
    // f += f;
    // debug(f);
    // debug(f.getSize());
    // f += f;
    // debug(f);
    // debug(f.getSize());
    // // String f = h + h;
    // debug((h += h));
    // debug(h.getSize());
    // h += h;
    // debug(h);
    // debug(h.getSize());
    //  cout << s.getSize() << endl;
    //  // s << cout;
    //  cout << s << endl;
    //  // cin>>s;
    //  // cout<<s<<endl;
    //  String p(s);
    //  debug(p.getSize());
    //  debug(p);

    // char tmp2[11] = "9087654321";
    // String f = (tmp2);
    // debug((p == s));
    // debug((p == f));
    // debug(f);
    // debug((p != s));
    // debug((f != s));
    // String e;
    // debug(!e);
    // debug(!f);
    // debug((f < p));
    // debug((f > p));
    // debug((f < e));
    // debug((f > e));
    // debug((s < p));
    // debug((s > p));

    // f=p;
    // debug(f);
    // p = f;
    // debug(p);
    // cout<<p.c_str()<<endl;
    //
    // p = p + f;
    // debug(p);
    // debug(p.getSize());
    // debug((p+p));
    // debug((p+=p));
    // char a[10];
    // a[0]='1';
    // a[1]='2';
    // a[2]='\0';
    // debug(a);
    // debug(strlen(a));
    // debug(p.c_str());
    // debug(strlen(p.c_str()));

    return 0;
}