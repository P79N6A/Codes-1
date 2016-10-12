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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

struct Edge {
    int to, next, w;
}edge[2 * MAXN];
int head[MAXN], tot;

int n, k, ans;
int subSize[MAXN];
bool vis[MAXN];

void init() {
    ans = tot = 0;
    memset(vis, 0, sizeof vis);
    memset(head, -1, sizeof head);
}

void add_edge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int compute_subSize(int u, int p) {
    int c = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != p && !vis[v]) c += compute_subSize(v, u);
    }
    return subSize[u] = c;
}

// 寻找删除该点后最大子树的顶点数最少的点
pii search_it(int u, int p, int t) {
    pii ret = make_pair(INF, -1);
    int s = 1, m = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != p && !vis[v]) {
            ret = min(ret, search_it(v, u, t));
            m = max(m, subSize[v]);
            s += subSize[v];
        }
    }
    m = max(m, t - s); // t - s:包含u点的子树顶点个数
    return min(ret, make_pair(m, u));
}

void getdis(int u, int p, int d, vector<int> &ds) {
    ds.push_back(d);
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != p && !vis[v]) getdis(v, u, d + edge[i].w, ds);
    }
}

int countAns(vector<int> &ds) {
    int ret = 0;
    sort(ds.begin(), ds.end());
    int i = 0, j = ds.size() - 1;
    while (i < j) {
        while (ds[i] + ds[j] > k && i < j) --j;
        ret += j - i;
        ++i;
    }
    return ret;
}

void solve(int v) {
    // 找重心
    compute_subSize(v, -1);
    int s = search_it(v, -1, subSize[v]).second;
    vis[s] = 1;

    // 继续划分
    for (int i = head[s]; ~i; i = edge[i].next) {
        if (!vis[edge[i].to]) solve(edge[i].to);
    }

    // 计算个数
    vector<int> ds;
    ds.push_back(0); // 距离s为0的虚拟点
    for (int i = head[s]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (vis[v]) continue;

        vector<int> tds;
        getdis(v, s, edge[i].w, tds);

        ans -= countAns(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }

    ans += countAns(ds);
    vis[s] = 0; // 复原，为大子树计算服务2333
}

int main()
{
    while (~scanf("%d%d", &n, &k) && (n | k)) {
        init();
        int u, v, l;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &l);
            add_edge(u, v, l);
            add_edge(v, u, l);
        }
        solve(1);
        printf("%d\n", ans);
    }
    return 0;
}
