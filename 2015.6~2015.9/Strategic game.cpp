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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1511;
int n, dp[MAXN][2];
vector<int> v[MAXN];

void dfs(int u, int f)
{
    dp[u][0] = 0, dp[u][1] = 1;
    for (int i = 0; i < v[u].size(); ++i)
    {
        int now = v[u][i];
        if (now == f) continue;
        dfs(now, u);
        dp[u][1] += min(dp[now][0], dp[now][1]);
        dp[u][0] += dp[now][1];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i) v[i].clear();
        for (int i = 0; i < n; ++i)
        {
            int u, k, to;
            scanf("%d:(%d)", &u, &k);
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &to);
                v[u].push_back(to);
                v[to].push_back(u);
            }
        }
        dfs(0, -1);
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }
    return 0;
}

