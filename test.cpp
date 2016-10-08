#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

int c[MAXN], G[MAXN][MAXN];
int topo[MAXN], t, n;

bool dfs(int u) {
    c[u] = -1;
    for (int v = 0; v < n; ++v) {
        if (G[u][v]) {
            if (c[v] < 0) return false;
            else if (!c[v] && !dfs(v)) return false;
        }
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}

bool toposort() {
    t = n;
    memset(c, 0, sizeof c);
    for (int u = 0; u < n; ++u) if (!c[u] && !dfs(u)) {
        return false;
    }
    return true;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    return 0;
}
