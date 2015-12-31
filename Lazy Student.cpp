#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int x[MAXN], y[MAXN];    // 为1的边连接的两点
int ex[MAXN], ey[MAXN];  // 为0的边连接的两点
struct Edge
{
    int w, id;
    bool in;
    Edge(int _w = 0, bool _in = 0, int _id = 0):w(_w), in(_in), id(_id){}
    bool operator < (const Edge &t)const
    {
        if (w == t.w) return in > t.in;  // 注意还要对0、1排序
        return w < t.w;
    }
}edge[MAXN];

int main()
{
    int n, m, u, w; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &w);
        edge[i] = Edge(u, w, i);
    }
    sort(edge, edge + m);

    bool flag = 0;
    // cnt:1->2->3->..   cnt2:统计到出cnt2为止需要多少条树外边
    // ecnt:可以构建的边
    int cnt = 1, cnt2 = 0, ecnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int id = edge[i].id;
        if (edge[i].in)
        {
            x[id] = cnt, y[id] = ++cnt;
            if (ecnt > 1e5) continue; // 最多可以构建n * n条，然后1e5就够了
            for (int j = 1; j <= cnt - 2; ++j) // 每多一个点所新建立的边
            {
                ex[ecnt] = cnt, ey[ecnt++] = j;
                if (ecnt > 1e5) break;
            }
        }
        else
        {
            x[id] = ex[cnt2], y[id] = ey[cnt2];
            ++cnt2;
            if (ecnt < cnt2) // 可建立的边数 < 需要数，之后必然违反MST特性
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag) printf("-1\n");
    else
    {
        for (int i = 0; i < m; ++i)
            printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}
