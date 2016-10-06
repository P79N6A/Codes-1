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
const int MAXN = 1e6 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int head[MAXN], tol;
int par[MAXN], cnt[MAXN];
bool vis[MAXN];

inline void init(int n) {
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
        par[i] = i;
        cnt[i] = 1;
    }
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    init(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
        u = find(u), v = find(v);
        if (u == v) continue;
        par[u] = v;
        cnt[v] += cnt[u];
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        int u = find(i);
        if (!vis[u]) v.push_back(cnt[u]);
        vis[u] = 1;
    }
    sort(v.begin(), v.end());
    int num = 0;
    int have = 0, first = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) ++num;
        else {
            have += min(k, v[i]) - first;
            first = 1;
        }
    }
    num -= have;
    if (num <= 0) cout << 0 << '\n';
    else {
        int link = num / 2;
        int sum = num + (have != 0) - link;
        cout << sum - 1 << '\n';
    }
    return 0;
}
