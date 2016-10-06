#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Edge {
    int u, v;
    Edge(int _u = 0, int _v = 0): u(_u), v(_v){}
};

int p[1111];
vector<Edge> blue, red;

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    p[x] = y;
}

int main()
{
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k) && (n || m || k)) {
        char op[2];
        int u, v, cntr = 0, cntb = 0;
        blue.clear(); red.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &u, &v);
            if (op[0] == 'B') blue.push_back(Edge(u, v));
            else red.push_back(Edge(u, v));
        }

        int mx = 0; // 这里统计蓝边之后没必要继续了，需要的信息已经都得到了
        for (int i = 1; i <= n; ++i) p[i] = i;
        for (int i = 0; i < blue.size(); ++i) {
            int x = blue[i].u, y = blue[i].v;
            if (find(x) != find(y)) {
                unite(x, y);
                ++mx;
            }
        }

        int mi = 0;
        for (int i = 1; i <= n; ++i) p[i] = i;
        for (int i = 0; i < red.size(); ++i) {
            int x = red[i].u, y = red[i].v;
            if (find(x) != find(y)) unite(x, y);
        }
        for (int i = 0; i < blue.size(); ++i) {
            int x = blue[i].u, y = blue[i].v;
            if (find(x) != find(y)) {
                unite(x, y);
                ++mi;
            }
        }

        if (mi <= k && k <= mx) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
