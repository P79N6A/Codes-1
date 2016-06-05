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
const int MAXN = 111;

struct P {
    int v, w;
    P(int a, int b): v(a), w(b){};
};
struct PP {
    int u, k, len;
    PP(int a, int b, int c): u(a), k(b), len(c){};
};
vector<P> G[MAXN];
int dis[MAXN][20][MAXN * 5];
bool in[MAXN][20][MAXN * 5];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, a, b, n, m, l, k, u, v, w; cin >> t;
    while (t --) {
        cin >> a >> b >> m >> l >> k;
        n = a + b;
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            G[u].push_back(P(v, w));
            G[v].push_back(P(u, w));
        }
        memset(dis, 0x3f, sizeof dis);
        memset(in, 0, sizeof in);
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= l; ++j) {
                dis[n][i][j] = 0;
                in[n][i][j] = 1;
            }
        }
        queue<PP> q;
        q.push(PP(n, k, l));
        while (q.size()) {
            PP cur = q.front(); q.pop();
            int u = cur.u, lef = cur.k, len = cur.len;
            for (int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i].v, w = G[u][i].w;
                if (len < l) {
                    if (dis[u][lef][len] + w < dis[v][lef - 1][l]) {
                        dis[v][lef - 1][l] = dis[u][lef][len] + w;
                        if (!in[v][lef - 1][l]) {
                            in[v][lef - 1][l] = 1;
                            q.push(PP(v, lef - 1, l));
                        }
                    }
                }
                if (lef > 0 || G[u][i].w <= len) {
                    if (dis[u][lef][len] < dis[v][lef][len - w]) {
                        dis[v][lef][len - w] = dis[u][lef][len];
                        if (!in[v][lef][len - w]) {
                            in[v][lef][len - w] = 1;
                            q.push(PP(v, lef, len - w));
                        }
                    }
                }
            }
        }
    }
    return 0;
}
