#include<algorithm>
#include<bitset>
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
#define pil pair<int, ll>
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e3 + 5;

vector<pil> G[MAXN];
int pre[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
vector<int> ans;
int n, m, u, v, w;
ll t;

struct P {
    ll cost;
    int u, w;
    bool operator < (const P&t)const {
        return cost > t.cost;
    }
};

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d%I64d", &n, &m, &t);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (u == n) continue;
        G[u].push_back(pil(v, w));
    }
    priority_queue<P> pq;
    memset(dis, 0x3f, sizeof dis);
    dis[1][1] = 0;
    pq.push(P{0, 1, 1});
    while (pq.size()) {
        P cur = pq.top(); pq.pop();
        int u = cur.u, w = cur.w;
        ll c = cur.cost;
        if (vis[u][w]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].first, cc = G[u][i].second;
            if (c + cc > t) continue;
            if (c + cc < dis[v][w + 1]) {
                dis[v][w + 1] = c + cc;
                pre[v][w + 1] = u;
                pq.push(P{dis[v][w + 1], v, w + 1});
            }
        }
        vis[u][w] = 1;
    }
    int i;
    for (i = n; i >= 1; --i) {
        if (dis[n][i] <= t) break;
    }
    int temp = n;
    while (temp) {
        ans.push_back(temp);
        temp = pre[temp][i];
        --i;
    }
    printf("%d\n", ans.size());
    for (int i = ans.size() - 1; i >= 0; --i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
