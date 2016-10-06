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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 150;

int n, ans;
int g[MAXN][MAXN];
int S, all[MAXN][MAXN], some[MAXN][MAXN], none[MAXN][MAXN];
//下标从1开始
//all为已取顶点集，some为未处理顶点集，none为不取的顶点集
//我们求最大团顶点数时只要some，要求记录路径时要all和some，这里求极大团数量，需要all、some、none
void dfs(int d, int an, int sn, int nn)
{
    if(S > 1000) return ; // 极大团数量超过1000就不再统计
    if(sn == 0 && nn == 0) ++S;//sn==0搜索到终点，只有nn==0时，才是一个极大团
    int u = some[d][0];//pivot vertex
    for(int i = 0; i < sn; ++i)
    {
        int v = some[d][i];
        if(g[u][v] || !v) continue;
        int tsn = 0, tnn = 0;
        for(int j = 0; j < an; j ++) all[d + 1][j] = all[d][j];
        all[d + 1][an] = v;
        for(int j = 0; j < sn; ++j) if(g[v][some[d][j]]) some[d + 1][tsn++] = some[d][j];
        for(int j = 0; j < nn; ++j) if(g[v][none[d][j]]) none[d + 1][tnn++] = none[d][j];
        dfs(d + 1, an + 1, tsn, tnn);
        //把v从some取出，放入none
        some[d][i] = 0, none[d][nn++] = v;
    }
}

void MaxClique() {
    S = 0;
    for(int i = 0; i < n; ++i) some[0][i] = i + 1;
    dfs(0, 0, n, 0);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, u, v;
    while (~scanf("%d%d", &n, &m)) {
        memset(g, 0, sizeof g);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        MaxClique();
        if (S > 1000) puts("Too many maximal sets of friends.");
        else printf("%d\n", S);
    }
    return 0;
}
