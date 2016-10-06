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

int u[MAXN << 2], v[MAXN << 2], len[MAXN << 2];
int deg[MAXN];
ll dis[MAXN];
struct P {
    int to, len;
};
vector<P> G[MAXN];

bool in[MAXN];
void spfa(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    queue<int> q; q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].to;
            if (dis[v] > dis[u] + G[u][i].len) {
                dis[v] = dis[u] + G[u][i].len;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &len[i]);
        G[u[i]].push_back(P{v[i], len[i]});
        G[v[i]].push_back(P{u[i], len[i]});
    }
    for (int i = m; i < m + k; ++i) {
        scanf("%d%d", &v[i], &len[i]);
        G[1].push_back(P{v[i], len[i]});
        G[v[i]].push_back(P{1, len[i]});
    }
    spfa(1);
    for (int i = 0; i < m; ++i) {
        int x = u[i], y = v[i];
        if (dis[x] == dis[y] + len[i]) {
            ++deg[x];
        }
        else if (dis[y] == dis[x] + len[i]) {
            ++deg[y];
        }
    }
    int ans = 0;
    for (int i = m; i < m + k; ++i) {
        int x = 1, y = v[i];
        if (dis[y] == dis[x] + len[i]) {
            if (deg[y]) ++ans;
            ++deg[y];
        }
        else ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
