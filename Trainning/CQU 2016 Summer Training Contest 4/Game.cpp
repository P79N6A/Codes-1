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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 211;

int deg[MAXN], org[MAXN];
bool vis[MAXN];
int belong[MAXN], n;
vector<int> G[MAXN];
vector<int> f[4];

int solve(int x) {
    memcpy(deg, org, sizeof org);
    memset(vis, 0, sizeof vis);
    int ans = 0;
    bool first = 1;
    while (1) {
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) return ans;
        if (!first) {
            x = x + 1;
            if (x == 4) x = 1;
            ++ans;
        }
        first = 0;
        queue<int> q;
        for (int i = 0; i < f[x].size(); ++i) {
            int u = f[x][i];
            if (!deg[u] && !vis[u]) q.push(u), vis[u] = 1;
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            ++ans;
            for (int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                if (--deg[v] == 0 && belong[v] == x) {
                    vis[v] = 1;
                    q.push(v);
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
    int x, k; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        belong[i] = x;
        f[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        org[i] = k;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            G[x].push_back(i);
        }
    }
    printf("%d\n", min(solve(1), min(solve(2), solve(3))));
    return 0;
}
