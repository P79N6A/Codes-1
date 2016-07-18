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
int p[MAXN], n;
double sz[MAXN];
double dp[MAXN];

double dfs(int u) {
    sz[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        sz[u] += dfs(v);
    }
    return sz[u];
}

void getAns(int u) {
    dp[u] = dp[p[u]] + 1 + (sz[p[u]] - sz[u] - 1) / 2.0;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        getAns(v);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x;
    scanf("%d", &n);
    p[1] = 1;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &x);
        p[i] = x;
        G[x].push_back(i);
    }
    dfs(1);
    dp[1] = 1;
    for (int i = 0; i < G[1].size(); ++i) getAns(G[1][i]);
    for (int i = 1; i <= n; ++i) {
        printf("%.2f ", dp[i]);
    }
    return 0;
}
