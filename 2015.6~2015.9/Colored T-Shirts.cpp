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
typedef long long ll;
vector<int> vec[20];
int pre[20][20];
ll dp[1 << 16];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n, m;
	for (int kase = scanf("%d", &t); kase <= t; ++kase)
	{
	    scanf("%d%d", &n, &m);
	    for (int i = 0; i < m; ++i) vec[i].clear();
	    for (int i = 0; i < n; ++i)
	    {
	        int color;
	        scanf("%d", &color);
	        vec[color - 1].push_back(i);
	    }
        memset(pre, 0, sizeof pre);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (i != j)
                {
                    for (int u = 0, v = 0; u < vec[i].size(); ++u)
                    {
                        while (v < vec[j].size() && vec[j][v] < vec[i][u])
                            ++v;
                        pre[i][j] += v;
                    }
                }
            }
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i < (1 << m); ++i)
            for (int j = 0; j < m; ++j) if(!(i >> j & 1))
            {
                ll sum = 0;
                for (int k = 0; k < m; ++k) if(!(i>>k&1)&&k!=j)
                    sum += pre[j][k];
                dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i] + sum);
            }
        printf("Case %d: %lld\n", kase, dp[(1<<m)-1]);
	}
	return 0;
}

