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
const int MAXN = 1e3 + 111;
const int MAXM = 5e4 + 111;

int n, m;
vector<int> G[MAXN], rG[MAXN], nG[MAXN];
vector<int> vs;
bool used[MAXN];
int block;

int belong[MAXN], num[MAXN], dp[MAXN];
int a[MAXM], b[MAXM];

void init() {
    block = 0;
    for (int i = 0; i <= n; ++i) {
        num[i] = dp[i] = 0;
        G[i].clear();
        rG[i].clear();
        nG[i].clear();
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < G[v].size(); ++i) {
        if (!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = 1;
    belong[v] = k;
    ++num[k];
    for (int i = 0; i < rG[v].size(); ++i) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc() {
    vs.clear();
    memset(used, 0, sizeof used);
    for (int v = 1; v <= n; ++v) {
        if (!used[v]) dfs(v);
    }
    memset(used, 0, sizeof used);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; --i) {
        if (!used[vs[i]]) rdfs(vs[i], ++k);
    }
    return k;
}

int dfsans(int x) {
    if (nG[x].size() == 0) dp[x] = num[x];
    if (dp[x]) return dp[x];

    int mx = 0;
    for (int i = 0; i < nG[x].size(); ++i) {
        mx = max(mx, dfsans(nG[x][i]));
    }
    return dp[x] = num[x] + mx;
}

int main()
{
    int kase, u, v; scanf("%d", &kase);
    while (kase --) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            a[i] = u, b[i] = v;
            G[u].push_back(v);
            rG[v].push_back(u);
        }

        block = scc();
        for (int i = 0; i < m; ++i) {
            if (belong[a[i]] == belong[b[i]]) continue;
            nG[belong[a[i]]].push_back(belong[b[i]]);
            //cout << a[i] << "->" << b[i] << endl;
            //cout << belong[a[i]] << "->" << belong[b[i]] << endl;
        }

        int ans = 0;
        for (int i = 1; i <= block; ++i) {
            ans = max(ans, dfsans(i));
        }

        printf("%d\n", ans);
    }
    return 0;
}
