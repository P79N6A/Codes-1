/*
 * 最小生成树注意判断无解的情况
 * 判断无解可以在prim函数中，最
 * 终判断是否全部点都被访问过
 */
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

vector<pii> G[MAXN];
int cost[MAXN];
bool vis[MAXN];

int prim(int s) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, s));
    cost[s] = 0;
    int ret = 0;
    while (pq.size()) {
        int u = pq.top().second, cc = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].first, add = G[u][i].second;
            if (cost[v] > add) {
                cost[v] = add;
                pq.push(pii(cost[v], v));
            }
        }
        ret += cc;
        vis[u] = 1;
    }
    return ret;
}

int main()
{
    int n, m, u, v;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            cost[i] = INF;
            vis[i] = 0;
        }
        int w;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &w);
                if (i != j) G[i].push_back(pii(j, w));
            }
        }
        scanf("%d", &m);
        while (m --) {
            scanf("%d%d", &u, &v);
            G[u].push_back(pii(v, 0));
            G[v].push_back(pii(u, 0));
        }
        printf("%d\n", prim(1));
    }
    return 0;
}
