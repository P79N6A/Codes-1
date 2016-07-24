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
const int MAXN = 2e5 + 111;

int p[MAXN];
int vis[MAXN];
int low[MAXN], dfn[MAXN], in[MAXN], indx, top, sta[MAXN], id[MAXN], scc;
int rt = -1;
int num[MAXN];
int tp[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    sta[top++] = u;
    int v = p[u];
    if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if (in[v]) {
        low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        int v;
        ++scc;
        int tol = 0;
        tp[scc] = u;
        do {
            v = sta[--top];
            in[v] = 0;
            ++tol;
            id[v] = scc;
        }while (v != u);
        num[scc] = tol;
    }
    return;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int cnt = 0, ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
        if (p[i] == i) {
            if (++cnt > 1) {
                p[i] = rt;
                ++ans;
            }
            else rt = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= scc; ++i) {
//        pr(num[i])
        if (num[i] > 1) {
            if (rt == -1) rt = tp[i];
            p[tp[i]] = rt;
            ++ans;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", p[i]);
    }
    return 0;
}
