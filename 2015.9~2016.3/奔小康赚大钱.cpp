#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 311;

int n, nx, ny;
int match[MAXN], lx[MAXN], ly[MAXN], slack[MAXN]; // lx[]左标杆 ly[]右标杆 slack[]松弛量
int visx[MAXN], visy[MAXN], w[MAXN][MAXN];

int dfs(int x)
{
    visx[x] = 1;
    for (int y = 1; y <= ny; ++y)
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
        else if (slack[y] > temp) slack[y] = temp;
    }
    return 0;
}

int KM()
{
    // 1.initialize
    int i, j;
    memset(match, -1, sizeof match);
    memset(ly, 0, sizeof ly);
    for (i = 1; i <= nx; ++i)
        for (j = 1, lx[i] = -INF; j <= ny; ++j)
            if (w[i][j] > lx[i]) lx[i] = w[i][j];

    // 2.find
    for (int x = 1; x <= nx; ++x)
    {
        for (i = 1; i <= ny; ++i) slack[i] = INF;
        while (1)
        {
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if (dfs(x)) break;

            // 能到达这一步，说明再也挪不到新边给x了，所以要进行增广，增加新边来选择
            int d = INF;
            // 没有匹配的y，且两者有边相连
            for (i = 1; i <= ny; ++i) if (!visy[i] && d > slack[i])
                d = slack[i];
            for (i = 1; i <= nx; ++i) if (visx[i]) lx[i] -= d;
            for (i = 1; i <= ny; ++i)
            {
                if (visy[i]) ly[i] += d;
                else slack[i] -= d; // 更改松弛量
            }                       // 本来这些点是要松弛D的，结果已经松弛了d，那么之后如果要松弛只用松弛D - d就行了
        }
    }

    int ret = 0;
    for (i = 1; i <= ny; ++i)
        if (match[i] != -1) ret += w[match[i]][i];
    return ret;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        nx = ny = n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &w[i][j]);
        printf("%d\n", KM());
    }
    return 0;
}
