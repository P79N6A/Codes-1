#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, dp[25][25][25][25];
bool has[25][25]; //记录格点是否有樱桃

int sum(int u, int d, int l, int r) //统计区域的樱桃数
{
    int ret = 0;
    for (int i = u + 1; i <= d; ++i)
        for (int j = l + 1; j <= r; ++j)
        {
            if (has[i][j]) ++ret;
            if (ret == 2) return 2; //超过两个也就是多个的情况可以统一递归处理，直接视为同一情况
        }
    return ret;
}

int dfs(int u, int d, int l, int r)
{
    int &ret = dp[u][d][l][r];
    if (ret != -1) return ret;
    int total = sum(u,d,l,r);
    if (total == 1) return ret = 0; //一个樱桃返回0，无需切割了
    if (!total) return ret = INF;  //没有樱桃，无效切割
    ret = INF;
    for (int i = u + 1; i < d; ++i) //水平切割
        ret = min(ret, dfs(u,i,l,r) + dfs(i,d,l,r) + r - l);
    for (int i = l + 1; i < r; ++i) //垂直切割
        ret = min(ret, dfs(u,d,l,i) + dfs(u,d,i,r) + d - u);
    return ret;
}

int main()
{
	int k, x, y, kase = 0;
    while(cin >> n >> m >> k)
    {
	   memset(dp, -1, sizeof dp);
	   memset(has, 0, sizeof has);
	   for (int i = 0; i < k; ++i) cin >> x >> y, has[x][y] = 1;
	   cout << "Case " << ++kase << ": " << dfs(0, n, 0, m) << '\n';
    }
	return 0;
}

