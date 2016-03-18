#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 20;
int x[MAXN], y[MAXN], line[MAXN][MAXN], n, dp[1 << 16];

void init()
{
    memset(line, 0, sizeof line);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            line[i][j] = (1 << i) | (1 << j);
            int dx = x[j] - x[i], dy = y[j] - y[i];
            for (int k = j + 1; k < n; ++k)
            {
                int dx2 = x[k] - x[i], dy2 = y[k] - y[i]; //这里我用了向量平行的条件
                if (dx2 * dy == dy2 * dx)
                    line[i][j] |= (1 << k);
            }
            line[j][i] = line[i][j];
        }
}

int dfs(int s)
{
    int& ret = dp[s];
    if (dp[s] < INF) return ret;
    int num = __builtin_popcount(s); //计算s中有几个1.很好用的函数
    if (num <= 2) return ret = 1;
    int i = 0;
    while (!(s & (1 << i))) ++i; //找出第一个没被删除的点
    for (int j = i + 1; j < n; ++j) //和其它点进行匹配。这里匹配次序是不会影响最终结果的
    {
        if (s & (1 << j))
        {
            ret = min(ret, dfs(s&(~line[i][j])) + 1);
        }
    }
    return ret;
}

int main()
{
	int t;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", x+i, y+i);
        init();
        printf("Case %d: %d\n", kase, dfs((1 << n) - 1));
    }
	return 0;
}

