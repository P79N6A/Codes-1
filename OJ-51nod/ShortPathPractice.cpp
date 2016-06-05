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
const int MAXN = 500 + 111;
struct P {
    int v, w;
    P(int a, int b):v(a), w(b){};
};
vector<P> G[MAXN];
int dis[MAXN], in[MAXN], w[MAXN];
int val[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, s, t, u, v, ww;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; ++i) cin >> val[i];
    memset(dis, 0x3f, sizeof dis);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> ww;
        G[u].push_back(P(v, ww));
        G[v].push_back(P(u, ww));
    }
    dis[s] = 0;
    w[s] = val[s];
    queue<int> q;
    q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].v;
            if (dis[v] > dis[u] + G[u][i].w) {
                dis[v] = dis[u] + G[u][i].w;
                w[v] = w[u] + val[v];
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
            else if (dis[v] == dis[u] + G[u][i].w) {
                if (w[v] < w[u] + val[v]) {
                    w[v] = w[u] + val[v];
                    if (!in[v]) {
                        in[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << dis[t] << ' ' << w[t] << '\n';
    return 0;
}
