/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: ALGraph.h
 * @filepath: cpp\ALGraph.h
 * @date: 2022-10-17 18:30:41
 * @description: 邻接表 有向有权图
 */

#include <iostream>
using namespace std;
struct Node {
    int w;
    int to;
    Node* next;
    Node() : next(NULL){};
    Node(int to, int w) : to(to), w(w), next(NULL){};
} * G[1000];
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
    }
    cout << "输入完成！" << endl;
}
/**
 * @date: 2022-10-17 19:01:50
 * @description: 今天只能到这里了，我得赶紧搞完，还有理论要复习，以及要去刷点题目提高算法手感
 */
void print() {
}
void DFS();
void BFS();
void Dij();
void Floyd();
void prim();
void kruskal();

int main() {
    cout << "请输入定点数和边数" << endl;
    cin >> n >> e;
    create();
    ///
    print();

    return 0;
}