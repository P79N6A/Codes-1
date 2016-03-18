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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 511;

bool vis[MAXN];
int match[MAXN];
vector<int> G[MAXN];

bool dfs(int x) {
    for (int i = 0; i < G[x].size(); ++i) {
        int v = G[x][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (!match[v] || dfs(match[v])) {
                match[v] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, u, v;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
