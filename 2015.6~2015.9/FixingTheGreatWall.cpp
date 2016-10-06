#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1111;
double dp[MAXN][MAXN][2], sum[MAXN], v, x;
int vis[MAXN][MAXN][2], n, kase;
struct P{
    double x, cost, add;
    bool operator <(const P &t)const
    {
        return x < t.x;
    }
}p[MAXN];

double dfs(int l, int r, int st)
{
    if (l == 1 && r == n) return 0;
    double &ret = dp[l][r][st];
    if (vis[l][r][st] == kase) return ret;
    vis[l][r][st] = kase;
    ret = INF;
    double now = (st == 0 ? p[l].x : p[r].x);
    double t, cost;
    if (l > 1)
    {
        t = (now - p[l - 1].x) / v;
        cost = (sum[l - 1] + sum[n] - sum[r]) * t + p[l - 1].cost;
        ret = min(ret, dfs(l - 1, r, 0) + cost);
    }
    if (r < n)
    {
        t = (p[r + 1].x - now) / v;
        cost = (sum[l - 1] + sum[n] - sum[r]) * t + p[r + 1].cost;
        ret = min(ret, dfs(l, r + 1, 1) + cost);
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    while(cin >> n >> v >> x && n)
	{
	    ++kase;
	    for (int i = 1; i <= n; ++i)
	    {
            scanf("%lf%lf%lf", &p[i].x, &p[i].cost, &p[i].add);
        }
        sort(p + 1, p + n + 1);
        p[0].x = -INF, p[n + 1].x = INF;
        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = sum[i - 1] + p[i].add;
        }
        double t, cost, ans = INF;
        for (int i = 1; i <= n + 1; ++i)
        {
            if (p[i - 1].x < x && x < p[i].x)
            {
                if (i > 1)
                {
                    t = (x - p[i - 1].x) / v;
                    cost = sum[n] * t + p[i - 1].cost;
                    ans = min(ans, dfs(i - 1, i - 1, 0) + cost);
                }
                if (i <= n)
                {
                    t = (p[i].x - x) / v;
                    cost = sum[n] * t + p[i].cost;
                    ans = min(ans, dfs(i, i, 1) + cost);
                }
                break;
            }
        }
        printf("%.0f\n", floor(ans));
	}
	return 0;
}

