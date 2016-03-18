#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2005;

struct Node {
    int lx, ly, rx, ry;
    int p, lson, rson, dep;
}node[MAXN];

int num[MAXN]; // 子节点个数

// 确定当前线段在哪个父节点下
int getPos(int p, int x, int y) {
    if (node[p].lson == 0) return p;
    int l = node[p].lson;
    if (node[l].lx <= x && x <= node[l].rx && node[l].ly <= y && y <= node[l].ry)
        return getPos(l, x, y);
    else return getPos(node[p].rson, x, y);
}

// 计算子节点个数
int getSon(int u) {
    num[u] = 0;
    if (node[u].lson == 0) return num[u] = 1;
    else {
        num[u] += getSon(node[u].lson) + getSon(node[u].rson);
    }
    return num[u];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int lx, ly, rx, ry, n, q;
    while (~scanf("%d%d%d%d", &lx, &ly, &rx, &ry)) {
        scanf("%d%d", &n, &q);
        int rt = 0, cnt = 1;
        node[rt] = (Node){lx, ly, rx, ry, -1, 0, 0, 0};

        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            if (lx > rx) swap(lx, rx);
            if (ly > ry) swap(ly, ry);
            int mx = (lx + rx) / 2, my = (ly + ry) / 2;

            int pos = getPos(0, mx, my);
            Node &t = node[pos];
            t.lson = cnt;
            node[cnt++] = (Node){t.lx, t.ly, rx, ry, pos, 0, 0, t.dep + 1};
            t.rson = cnt;
            node[cnt++] = (Node){lx, ly, t.rx, t.ry, pos, 0, 0, t.dep + 1};
        }

        getSon(0);

        while (q --) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            int p1 = getPos(0, lx, ly), p2 = getPos(0, rx, ry);
            while (p1 != p2) {
                if (node[p1].dep < node[p2].dep) p2 = node[p2].p;
                else if (node[p1].dep > node[p2].dep) p1 = node[p1].p;
                else {
                    p1 = node[p1].p;
                    p2 = node[p2].p;
                }
            }
            printf("%d\n", n + 1 - num[p1] + 1);
        }
    }
    return 0;
}
