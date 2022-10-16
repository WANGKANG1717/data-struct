/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: SqGraph.h
 * @filepath: head\SqGraph.h
 * @date: 2022-10-16 14:16:21
 * @description: 邻接矩阵存储的图
 */

#include <stdio.h>

#include <iostream>
using namespace std;

#ifndef __SQGRAPH_H__
#define __SQGRAPH_H__
/**
 * @date: 2022-10-16 14:17:14
 * @description: 为了简单起见（省时间），后面的（图，二叉检索树，平衡二叉树，查找，排序）不在使用模板了
 */

#define MAXINT 0x7f7f7f7f
#define MININT -0x7f7f7f7f
/**
 * @date: 2022-10-16 14:34:35
 * @description: 带权无向无环图 MAXINT代表无边 正数代表有边及便之间的权值
 */

/**
 * @date: 2022-10-16 15:06:29
 * @description: 接下啦的算法不再使用类实现了，没意思，太麻烦了
 *              而且考试时基本没用，算是浪费了想当多的时间，算是一个教训把
 */
class SqGraph {
   private:
    int **G;
    int n;
    int *vis;

   public:
    SqGraph(int n = 0);
    ~SqGraph();
    void init(int n);
    bool setEdge(int i, int j, int w);
    int getWeight(int i);
    int edgeNum();
    void print();
    //
    /**
     * @date: 2022-10-16 14:59:59
     * @description: 以上为基础算法
     */
    void dfs(int s);
    void DFS(int s);
    void bfs(int s);
    //最短路径
    void DIJ(int s);
    void Flord();
    //最小生成树
    void Kruskal();
    void Prim();
    //有向图的关键路径，拓扑排序
};
SqGraph::SqGraph(int n) {
    init(n);
    vis == NULL;
}

SqGraph::~SqGraph() {
    delete (G);
}
void SqGraph::init(int n) {
    if (n < 0) {
        cout << "Error: please input positive NUMBER!" << endl;
        exit(0);
    }
    G = new int *[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = MAXINT;
        }
    }
    this->n = n;
}

bool SqGraph::setEdge(int i, int j, int w) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        G[i][j] = w;
        G[j][i] = w;
        return true;
    } else {
        return false;
    }
}

int SqGraph::getWeight(int i) {
    int w = 0;
    for (int k = 0; k < n; k++) {
        if (G[i][k] != MAXINT) {
            w++;
        }
    }
    return w;
}

int SqGraph::edgeNum() {
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (G[i][j] != MAXINT) num++;
        }
    return num;
}

void SqGraph::print() {
    if (n == 0) {
        cout << " Error : Empty Graph !" << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10d ", G[i][j]);
        }
        cout << endl;
    }
}

void SqGraph::dfs(int s) {
    if (s >= n || s < 0) {
        cout << "Error: please input reasonable index!" << endl;
        return;
    }
    if (vis != NULL) delete (vis);
    vis = new int[n]{0};
    DFS(s);
}
void SqGraph::DFS(int s) {
    vis[s] = 1;
    cout << s << " ";
    for (int i = 0; i < n; i++) {
        if (!vis[i] && G[s][i] != MAXINT) {
            DFS(i);
        }
    }
}
void SqGraph::bfs(int s) {}
//最短路径
void SqGraph::DIJ(int s) {}
void SqGraph::Flord() {}
//最小生成树
void SqGraph::Kruskal() {}
void SqGraph::Prim() {}

#endif