/*
  (n - 1)!枚举阴的位置，然后对阳的可以放置
  位置进行二分图匹配。
 */
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 10;

bool mp[MAXN][MAXN];
int num[MAXN];
int n, m, u, v;
int match[MAXN];
bool nt[MAXN];
int vis[MAXN];
int len[MAXN];
int G[MAXN][MAXN];

void build() {
    num[n] = num[0];
    for (int i = 1; i <= n; ++i) {
        len[i] = 0;
        if (!nt[i]) continue;
        for (int j = 0; j < n; ++j) {
            int u = num[j], v = num[j + 1];
            if (mp[i][u] || mp[i][v]) {
                continue;
            }
//            pr(i) prln(j)
            G[i][len[i]++] = j;
        }
    }
}

bool dfs(int u, int flag) {
    for (int i = 0; i < len[u]; ++i) {
        int v = G[u][i];
        if (vis[v] == flag) continue;
        vis[v] = flag;
        if (match[v] == -1 || dfs(match[v], flag)) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int hungary() {
    int ret = 0;
    memset(match, -1, sizeof match);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (dfs(i, i)) ++ret;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        memset(mp, 0, sizeof mp);
        memset(nt, 0, sizeof nt);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            mp[u][v] = 1;
            nt[u] = 1;
        }
        int up = n;
        for (int i = 1; i <= n; ++i) {
            if (!nt[i]) --up;
        }
        num[0] = 1;
        for (int i = 1; i < n; ++i) num[i] = i + 1;
        int ans = INF;
        do {
            build();
            ans = min(ans, up - hungary());
            if (ans == 0) break;
        } while(next_permutation(num + 1, num + n));
        printf("%d\n", ans);
    }
    return 0;
}
