/* 题意：
 * 能否构造出符合条件要求的序列？
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

struct P {
    int v, w;
};
vector<P> G[MAXN]; // 图中点代表的意思为：到i位置的序列和
int dis[MAXN], n;
int num[MAXN];
bool in[MAXN];

bool spfa(int s) {
    in[s] = 1;
    queue<int> q;
    q.push(s);
    memset(dis, -0x3f, sizeof dis);
    memset(num, 0, sizeof num);
    dis[s] = 0;
    ++num[s];
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].v, w = G[u][i].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                    if (++num[v] > n + 1) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, u, v, w;
    char op[3];
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m);
        for (int i = 0; i <= n + 1; ++i) G[i].clear(), in[i] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%s%d", &u, &v, op, &w);
            v += u;
            --u;
            if (op[0] == 'g') G[u].push_back(P{v, w + 1});
            else G[v].push_back(P{u, -w + 1});
        }
        for (int i = 0; i <= n; ++i) {
            G[n + 1].push_back(P{i, 0});
        }
        if (spfa(n + 1)) puts("successful conspiracy");
        else puts("lamentable kingdom");
    }
    return 0;
}
