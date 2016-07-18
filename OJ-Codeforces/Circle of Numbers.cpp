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
const int MAXN = 1e5 + 111;

vector<int> G[MAXN];
bool vis[MAXN];
int ans[MAXN], indx = 0, n;

bool dfs(int u, int v, int f, int len) {
    ans[len - 1] = u;
    ans[len] = v;
    if (len < n) {
        vis[v] = 1;
        for (int i = 0; i < 4; ++i) {
            int w = G[v][i];
            if (vis[w] || w == f) continue;
            bool flag = 0;
            for (int j = 0; j < 4; ++j) {
                flag |= (w == G[u][j]);
            }
            if (flag && dfs(v, w, u, len + 1)) return 1;
        }
        vis[v] = 0;
        return 0;
    }
    else return v == 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int up, u, v;
    scanf("%d", &n);
    up = n << 1;
    bool re = 0;
    for (int i = 0; i < up; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        if (G[u].size() > 4 || G[v].size() > 4) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (dfs(1, G[1][i], -1, 1)) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", ans[i]);
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}
