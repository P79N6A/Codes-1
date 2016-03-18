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
const int MAXN = 4e3 + 111;

bool vis[MAXN][MAXN];
int deg[MAXN];

int a[MAXN], b[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++deg[a[i]];
        ++deg[b[i]];
        vis[a[i]][b[i]] = vis[b[i]][a[i]] = 1;
    }

    int ans = INF;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (vis[a[i]][j] && vis[j][b[i]]) {
                ans = min(ans, deg[a[i]] + deg[j] + deg[b[i]]);
            }
        }
    }
    if (ans == INF) ans = 5;
    cout << ans - 6 << '\n';
    return 0;
}
