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
const int MAXN = 411;

vector<int> G[2][MAXN];
int dis[2][MAXN], n, m;
bool in[MAXN];
bool mp[MAXN][MAXN];

void spfa(int s, int f) {
    queue<int> q;
    q.push(s);
    for (int i = 1; i <= n; ++i) dis[f][i] = INF;
    dis[f][s] = 0;
    while (q.size()) {
        int cur = q.front(); q.pop();
        in[cur] = 0;
        for (int i = 0; i < G[f][cur].size(); ++i) {
            int v = G[f][cur][i];
            if (dis[f][v] > dis[f][cur] + 1) {
                dis[f][v] = dis[f][cur] + 1;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        mp[u][v] = mp[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int f = mp[i][j];
            G[f][i].push_back(j);
            G[f][j].push_back(i);
        }
    }

    spfa(1, 0);
    spfa(1, 1);

    if (dis[0][n] == INF || dis[1][n] == INF) cout << -1 << '\n';
    else cout << max(1, max(dis[0][n], dis[1][n])) << '\n';

    return 0;
}
