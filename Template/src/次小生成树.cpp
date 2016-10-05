/*
 * 求出最小生成树，然后用mx[i][j]记录i到j的最大边，
 * 每次添加不在最小生成树上的边(u,v)时，先删除u,v
 * 在树上的最大边，然后添加进去
 */
const int INF = 0x3f3f3f3f;
const int MAXN = 111;
const int MAXM = 111*111;

bool used[MAXN][MAXN], vis[MAXN];
int cost[MAXN], mp[MAXN][MAXN];
int pre[MAXN];
int mx[MAXN][MAXN];
int u[MAXM], v[MAXM];

int prime(int n) {
    int ret = 0;
    memset(vis, 0, sizeof vis);
    memset(used, 0, sizeof used);
    memset(mx, 0, sizeof mx);
    pre[1] = -1;
    vis[1] = 1;
    cost[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cost[i] = mp[1][i];
        pre[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int mi = INF;
        int p = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && cost[j] < mi) {
                mi = cost[j];
                p = j;
            }
        }
		// 不连通
        if (mi == INF) return -1;
        ret += mi;
        vis[p] = 1;
        used[p][pre[p]] = used[pre[p]][p] = 1;
        for (int j = 1; j <= n; ++j) {
            if (vis[j]) mx[j][p] = mx[p][j] = max(mx[j][pre[p]], cost[p]);
            if (!vis[j] && cost[j] > mp[p][j]) {
                cost[j] = mp[p][j];
                pre[j] = p;
            }
        }
    }
    return ret;
}

int main()
{
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        memset(mp, 0x3f, sizeof mp);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
            scanf("%d", &mp[u[i]][v[i]]);
            mp[v[i]][u[i]] = mp[u[i]][v[i]];
        }
        int ans = prime(n);
		// 求出最小生成树
        int sub = INF;
        for (int i = 0; i < m; ++i) {
			// 边不在生成树上
            if (!used[u[i]][v[i]]) {
                sub = min(sub, ans - mx[u[i]][v[i]] + mp[u[i]][v[i]]);
            }
        }
        if (ans == sub) {
            puts("Not Unique!");
        }
        else printf("%d\n", ans);
    }
    return 0;
}
