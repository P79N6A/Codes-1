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
#define MP make_pair
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const ll INF = 1e10;
const int MAXN = 3e4 + 111;

vector<pii> G[MAXN];
struct Edge {
    int to, next, w;
}edge[2 * MAXN];
int head[MAXN], tot;

bool in[MAXN];
ll dis[MAXN];

int n, k, m;
ll ans, ansd;
int subSize[MAXN];
bool vis[MAXN];

void init() {
    ans = ansd = tot = 0;
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) G[i].clear();
}

void add_edge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void spfa() {
    queue<int> q;
    q.push(1);
    for (int i = 1; i <= n; ++i) dis[i] = INF, in[i] = 0;
    in[1] = 1;
    dis[1] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].first;
            ll Dis = G[u][i].second;
            if (!in[v] && dis[v] > dis[u] + Dis) {
                dis[v] = dis[u] + Dis;
                in[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i].first, Dis = G[u][i].second;
        if (!in[v] && dis[v] == dis[u] + Dis) {
            add_edge(u, v, Dis);
            add_edge(v, u, Dis);
            dfs(v);
        }
    }
}

void build_tree() {
    for (int i = 1; i <= n; ++i) {
        in[i] = 0;
        sort(G[i].begin(), G[i].end());
    }
    dfs(1);
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
    return min(ret, MP(m, u));
}

map<int, pii> ds;
map<int, pii> tds;
map<int, pii>::iterator it, itt;
void enumerate(int v, int p, int kk, int dis, map<int, pair<int, int> > &tds)
{
    if (kk > k) return;
    it = tds.find(kk);
    if (it!=tds.end()){
        if (it->second.first == dis) {
            it->second.second += 1;
        }
        else if(it->second.first<dis){
            tds.erase(it);
            tds.insert(MP(kk, MP(dis, 1)));
        }
    }
    else{
        tds.insert(MP(kk, MP(dis, 1)));
    }
    for (int i = head[v]; ~i; i = edge[i].next){
        int w = edge[i].to;
        if (w == p || vis[w]) continue;
        enumerate(w, v, kk + 1, dis + edge[i].w, tds);
    }
}

void solve(int v)
{
    compute_subSize(v, -1);
    int s = search_it(v, -1, subSize[v]).second;
    vis[s] = true;
    for (int i = head[s]; ~i; i = edge[i].next){
        if (vis[edge[i].to]) continue;
        solve(edge[i].to);
    }
    ds.clear();
    ds.insert(MP(1, MP(0, 1)));
    for (int i = head[s]; ~i; i = edge[i].next){
        if (vis[edge[i].to]) continue;
        tds.clear();
        enumerate(edge[i].to, s, 1, edge[i].w, tds);
        it = tds.begin();
        while (it != tds.end()){
            int kk = it->first;
            if (ds.count(k - kk)){
                itt = ds.find(k - kk);
                int ldis = it->second.first + itt->second.first;
                if (ldis>ansd) {
                    ansd = ldis; ans = it->second.second*itt->second.second;
                }
                else if (ldis == ansd){
                    ans += it->second.second*itt->second.second;
                }
            }
            ++it;
        }
        it = tds.begin();
        while (it != tds.end()){
            int kk = it->first + 1;
            if (ds.count(kk)){
                itt = ds.find(kk);
                if (it->second.first > itt->second.first){
                    ds.erase(itt);
                    ds.insert(MP(kk, it->second));
                }
                else if (it->second.first == itt->second.first) itt->second.second += it->second.second;
            }
            else{
                ds.insert(MP(kk, it->second));
            }
            ++it;
        }
    }
    vis[s] = false;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase; scanf("%d", &kase);
    while (kase --) {
        scanf("%d%d%d", &n, &m, &k);
        init();
        int u, v, w;
        while (m --) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(MP(v, w));
            G[v].push_back(MP(u, w));
        }
        spfa();
        build_tree();
        solve(1);
        printf("%lld %lld\n", ansd, ans);
    }
    return 0;
}
