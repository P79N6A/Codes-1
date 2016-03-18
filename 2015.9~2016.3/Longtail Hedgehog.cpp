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
using namespace std;

const int MAXN = 1e5 + 111;

vector<int> G[MAXN];
ll dp[MAXN];

int n, m;
ll ans = 0;

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < G[i].size(); ++j) {
            if (G[i][j] < i) {
                dp[i] = max(dp[i], dp[G[i][j]] + 1);
            }
        }
        ans = max(ans, G[i].size() * dp[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
