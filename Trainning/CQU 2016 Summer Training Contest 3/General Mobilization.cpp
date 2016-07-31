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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e3 + 111;

vector<pii> G[MAXN];
vector<pii> bak[MAXN];
int p[MAXN], pw[MAXN];
int ans[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq[MAXN];

void dfs(int u, int f) {
    p[u] = f;
    for (int i = 0; i < G[u].size(); ++i) {
        pii cur = G[u][i];
        int v = cur.first, w = cur.second;
        if (v == f) continue;
        pw[v] = w;
        dfs(v, u);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, x, u, v, w; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x, pq[i].push(make_pair(x, i));
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    dfs(1, 1);
    ans[1] = 0;
    pq[0].pop();
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            int cap = pw[j];
            while (cap-- && pq[j].size()) {
                pii cur = pq[j].top(); pq[j].pop();
                int id = cur.second;
                int v = p[j];
                if (v == 1) {
                    ans[id] = i;
                }
                else {
                    bak[v].push_back(cur);
                }
            }
        }
        for (int j = 2; j <= n; ++j) {
            while (bak[j].size()) {
                pq[j].push(bak[j].back());
                bak[j].pop_back();
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}
