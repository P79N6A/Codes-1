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
const int MAXN = 31;

struct Edge {
    int to, nxt, w;
}edge[MAXN * MAXN];
int hire[MAXN], have[MAXN], num[MAXN];
int head[MAXN], tol, dis[MAXN], ans;
bool in[MAXN];

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

void build(int ans) {
    tol = 0;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= 24; ++i) {
        addedge(i, i - 1, 0);
        addedge(i - 1, i, have[i]);
    }
    for (int i = 1; i < 8; ++i) {
        addedge(i, i + 16, ans - hire[i]);
    }
    for (int i = 8; i <= 24; ++i) {
        addedge(i, i - 8, -hire[i]);
    }
    addedge(24, 0, -ans);
}

bool spfa() {
    memset(dis, 0x3f, sizeof dis);
    memset(in, 0, sizeof in);
    memset(num, 0, sizeof num);
    queue<int> q;
    q.push(0);
    in[0] = 1;
    ++num[0];
    dis[0] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                    if (++num[v] > 24) return 0;
                }
            }
        }
    }
    return 1;
}

bool ok(int n) {
    ans = -1;
    int l = 0, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        build(mid);
        if (spfa()) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ~ans;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n, x; cin >> t;
    while (t --) {
        for (int i = 1; i <= 24; ++i) {
            cin >> hire[i];
            have[i] = 0;
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++have[x + 1];
        }
        if (ok(n)) {
            cout << ans << '\n';
        }
        else cout << "No Solution\n";
    }
    return 0;
}
