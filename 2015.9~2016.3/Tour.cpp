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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 211;

int lx[MAXN], ly[MAXN], match[MAXN], slack[MAXN], n, w[MAXN][MAXN];
bool visx[MAXN], visy[MAXN];

bool dfs(int x)
{
    visx[x] = 1;
    for (int y = 1; y <= n; ++y)
    {
        if (visy[y]) continue;
        int temp = lx[x] + ly[y] - w[x][y];
        if (temp == 0)
        {
            visy[y] = 1;
            if (match[y] == -1 || dfs(match[y]))
            {
                match[y] = x;
                return 1;
            }
        }
        else if (temp < slack[y]) slack[y] = temp;
    }
    return 0;
}

int KM()
{
    int i, j;
    memset(match, -1, sizeof(int) * (n + 2));
    memset(ly, 0, sizeof(int) * (n + 2));
    for (i = 1; i <= n; ++i)
    {
        for (j = 1, lx[i] = -INF; j <= n; ++j)
            if (w[i][j] > lx[i]) lx[i] = w[i][j];
    }

    for (int x = 1; x <= n; ++x)
    {
        for (i = 1; i <= n; ++i) slack[i] = INF;
        while (1)
        {
            memset(visx, 0, sizeof(bool)*(n + 2));
            memset(visy, 0, sizeof(bool)*(n + 2));
            if (dfs(x)) break;

            int d = INF;
            for (i = 1; i <= n; ++i) if (!visy[i] && slack[i] < d)
                d = slack[i];

            if (d == INF) return -1; // 无法松弛，返回-1

            for (i = 1; i <= n; ++i)
            {
                if (visx[i]) lx[i] -= d;
                if (visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }

    int ret = 0;
    for (i = 1; i <= n; ++i)
    {
        //cout << match[i] << ' ' << i << endl;
        if (match[i] != -1) ret += w[match[i]][i];
        else return -1;
    }
    return -ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a, b, c, t, m;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                w[i][j] = -INF;

        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a == b) continue;
            w[a][b] = max(w[a][b], -c); // 建立反向边
        }
        printf("%d\n", KM());
    }
    return 0;
}

