/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: ALGraph.h
 * @filepath: cpp\ALGraph.h
 * @date: 2022-10-17 18:30:41
 * @description: 邻接表 有向有权图
 */

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MAXN 100
#define MAXINT 0x7f7f7f7f
#define MAXINT_ 0x3f3f3f3f
#define cout(a, b) cout << "<" << a << " " << b << ">"
struct Node {
    int w;
    int to;
    Node* next;
    Node() : next(NULL){};
    Node(int to, int w) : to(to), w(w), next(NULL){};
} * G[MAXN];
int n, e;
void create() {
    for (int i = 0; i < n; i++) {
        G[i] = new Node();
    }
    int l, r, w;
    cout << "定点对以及权值0-" << n - 1 << endl;
    for (int k = 0; k < e; k++) {
        cin >> l >> r >> w;
        Node* tmp = new Node(r, w);
        tmp->next = G[l]->next;
        G[l]->next = tmp;
        //
        Node* tmp2 = new Node(l, w);
        tmp2->next = G[r]->next;
        G[r]->next = tmp2;
    }
    cout << "输入完成！" << endl;
}
/**
 * @date: 2022-10-17 19:01:50
 * @description: 今天只能到这里了，我得赶紧搞完，还有理论要复习，以及要去刷点题目提高算法手感
 */
void print() {
    for (int i = 0; i < n; i++) {
        Node* p = G[i]->next;
        cout << i << ":";
        while (p) {
            cout << "<" << p->to << " " << p->w << "> ";
            p = p->next;
        }
        cout << endl;
    }
}
bool vis[MAXN];
void DFS(int s) {
    cout << s << " ";
    vis[s] = true;
    Node* p = G[s]->next;
    while (p) {
        if (!vis[p->to]) {
            DFS(p->to);
            p = p->next;
        }
    }
}
void BFS(int s) {
    queue<int> Q;
    Q.push(s);
    cout << s << " ";
    vis[s] = true;
    while (!Q.empty()) {
        int k = Q.front();
        Q.pop();
        Node* p = G[k]->next;
        while (p) {
            int s = p->to;
            if (!vis[s]) {
                cout << s << " ";
                vis[s] = true;
                Q.push(s);
            }
            p = p->next;
        }
    }
}
int pre[MAXN];
int len[MAXN];
void Dij(int s) {
    fill(vis, vis + n, false);
    fill(pre, pre + n, -1);
    fill(len, len + n, MAXINT);
    len[s] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        int minw = MAXINT;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && len[j] < minw) {
                minw = len[j];
                k = j;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        Node* p = G[k]->next;
        while (p) {
            int j = p->to;
            int lenj = p->w;
            if (!vis[k] && len[k] + lenj < len[j]) {
                len[j] = len[k] + lenj;
                pre[j] = k;
            }
            p = p->next;
        }
    }
}
int len2[MAXN][MAXN];
int path[MAXN][MAXN];
void Floyd() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            len2[i][j] = MAXINT_;
            path[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        Node* p = G[i]->next;
        while (p) {
            int j = p->to;
            int w = p->w;
            len2[i][j] = w;
            path[i][j] = i;
            p = p->next;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (len2[i][k] + len2[k][j] < len2[i][j]) {
                    len2[i][j] = len2[i][k] + len2[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}
struct {
    int from;
    int w;
} Edge[MAXN];

void prim(int s) {
    cout << "----------------------------" << endl;
    for (int i = 0; i < n; i++) {
        Edge[i].from = -1;
        Edge[i].w = MAXINT_;
        vis[i] = false;
    }
    Edge[s].w = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        int minw = MAXINT_;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && Edge[j].w < minw) {
                k = j;
                minw = Edge[j].w;
            }
        }
        if (k == -1) return;
        vis[k] = true;
        cout << Edge[k].from << " " << k << ' ' << Edge[k].w << endl;
        Node* p = G[k]->next;
        while (p) {
            int j = p->to;
            int w = p->w;
            if (!vis[j] && Edge[j].w > w) {
                Edge[j].w = w;
                Edge[j].from = k;
            }
            p = p->next;
        }
    }
    cout << "---------------------Prim" << endl;
}

struct KEDGE {
    int from;
    int to;
    int w;
} kEdge[MAXN];
int cmp(KEDGE a, KEDGE b) {
    return a.w < b.w;
}
int B[MAXN];
void init() {
    for (int i = 0; i < MAXN; i++) {
        B[i] = i;
    }
}
int getRoot(int s) {
    return (B[s] == s) ? s : B[s] = getRoot(B[s]);
}
void merge(int i, int j) {
    int root1 = getRoot(i);
    int root2 = getRoot(j);
    if (root1 != root2) {
        B[root2] = root1;
    }
}
void kruskal() {
    int edgeCnt = 0;
    for (int i = 0; i < n; i++) {
        Node* p = G[i]->next;
        while (p) {
            int to = p->to;
            int w = p->w;
            kEdge[edgeCnt++] = {i, to, w};
            p = p->next;
        }
    }
    sort(kEdge, kEdge + edgeCnt, cmp);
    init();
    for (int i = 0; i < edgeCnt; i++) {
        int from = kEdge[i].from;
        int to = kEdge[i].to;
        if (getRoot(from) != getRoot(to)) {
            merge(from, to);
            cout << "<" << from << " " << to << " " << kEdge[i].w << ">" << endl;
        }
    }
}

int main() {
    cout << "请输入定点数和边数" << endl;
    cin >> n >> e;
    create();

    ///
    // print();
    // fill(vis, vis + n, false);
    // DFS(0);
    // fill(vis, vis + n, false);
    // BFS(0);
    // cout << endl;
    // Dij(0);
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << len[i] << " " << pre[i] << " " << endl;
    // }
    // Floyd();
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%10d ", len2[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << "----------" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%10d ", path[i][j]);
    //     }
    //     cout << endl;
    // }
    // prim(0);
    kruskal();

    return 0;
}

/**
 5 4
0 1 1
1 2 2
1 3 3
3 4 4
 */

/*
5 6
0 1 1
0 4 100
1 3 5
1 2 2
2 3 2
3 4 4
 */

/*
6 10
0 1 6
0 2 1
0 3 5
2 1 5
2 3 5
2 4 6
2 5 4
1 4 3
4 5 6
3 5 2
  */