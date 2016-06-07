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
const int MAXN = 5e3 + 111;
const int MAXM = 3e4 + 111;

struct P {
    int n, w;
    bool operator < (const P &t)const {
        if (t.w == w) return n < t.n;
        return w < t.w;
    }
}p[MAXN];
vector<int> G[MAXN];
vector<int> M[MAXN];
int dfn[MAXN], low[MAXN], id[MAXN], sta[MAXN], in[MAXN], w[MAXN], tol[MAXN];
int vis[MAXN];
int scc, top, indx;
int u[MAXM], v[MAXM];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        M[i].clear();
        vis[i] = 0;
        dfn[i] = 0;
        tol[i] = 0;
        in[i] = 0;
    }
    scc = top = indx = 0;
}

void flow(int par, int u) {
    vis[u] = par;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v] != par) {
            p[v].w += 1;
            //pr(v)
            flow(par, v);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "w", stdout);
    #endif
    cout << 1 << '\n';
    cout << 30 << ' ' << 29 << '\n';
    for (int i = 1; i <= 29; ++i) {
        cout << i << ' ' << i + 1 << '\n';
    }
    return 0;
}
