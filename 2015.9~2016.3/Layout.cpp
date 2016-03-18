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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 1e16;
const int MAXN = 1e3 + 111;

vector<pii> G[MAXN];
int ans, cnt[MAXN], sta[MAXN], n;
ll dis[MAXN];
bool in[MAXN];

bool spfa(int s) {
    dis[s] = 0;
    in[s] = 1;
    int top = 0;
    sta[top++] = s;
    while (top) {
        int cur = sta[--top];
        in[cur] = 0;
        ++cnt[cur];
        if (cnt[cur] > n) return 0;
        for (int i = 0; i < G[cur].size(); ++i) {
            int v = G[cur][i].first;
            if (dis[v] > dis[cur] + G[cur][i].second) {
                dis[v] = dis[cur] + G[cur][i].second;
                if (!in[v]) {
                    in[v] = 1;
                    sta[top++] = v;
                }
            }
        }
    }
    ans = dis[n];
    if (ans == INF)
        ans = -2;
}

int main()
{
    int ml, md; scanf("%d%d%d", &n, &ml, &md);
    int u, v, w;
    for (int i = 1; i <= n; ++i) dis[i] = INF;
    for (int i = 0; i < ml; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(pii(v, w));
        //G[v].push_back(pii(u, w));
    }
    for (int i = 0; i < md; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        //G[u].push_back(pii(v, -w));
        G[v].push_back(pii(u, -w));
    }

    if (spfa(1)) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
