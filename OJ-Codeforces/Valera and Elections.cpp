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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

vector<int> G[MAXN];
int num[MAXN];
int dp[MAXN];
bool is[MAXN];

void dfs(int u, int f) {
    dp[u] = is[u];
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v != f) {
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, u, v, w;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (w == 2)
            is[u] = is[v] = --w;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        if (is[i] && dp[i] == 1) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i == ans.size() - 1) putchar('\n');
        else putchar(' ');
    }
    return 0;
}
