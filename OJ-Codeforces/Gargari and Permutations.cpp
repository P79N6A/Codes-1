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
const int MAXN = 1111;

int a[6][MAXN], p[6][MAXN];
vector<int> G[MAXN];
int len[MAXN];

int dfs(int u) {
    if (len[u]) return len[u];
    int mx = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        mx = max(dfs(v), mx);
    }
    return len[u] = mx + 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            p[i][a[i][j]] = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            bool ok = 1;
            for (int k = 0; k < m; ++k) {
                if (p[k][i] > p[k][j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) G[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!len[i]) {
            ans = max(ans, dfs(i));
        }
    }
    printf("%d\n", ans);
    return 0;
}
