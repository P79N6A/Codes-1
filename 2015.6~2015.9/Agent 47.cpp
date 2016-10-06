#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1 << 16], t, n, a[20];
char sh[20][20];

int dfs(int s)
{
    int& ret = dp[s];
    if (ret < INF) return ret;
    for (int i = 0; i < n; ++i)
    {
        if (!(s >> i & 1))
        {
            int mxv = 1;
            for (int j = 0; j < n; ++j) //从杀死的人中拿到最6的枪
                if (s >> j & 1) mxv = max(mxv, sh[j][i] - '0');
            int add = (a[i] + mxv - 1)/mxv;
            ret = min(ret, dfs(s|1<<i) + add);
        }
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    for (int kase = scanf("%d",&t); kase <= t; ++kase)
    {
        scanf("%d",&n);
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%s", sh[i]);
        dp[(1 << n) - 1] = 0;
        printf("Case %d: %d\n", kase, dfs(0));
    }
	return 0;
}

