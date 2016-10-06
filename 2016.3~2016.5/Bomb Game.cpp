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
const int MAXN = 200 + 111;
const double eps = 1e-4;

double x[MAXN], y[MAXN];
vector<int> G[MAXN];
double mp[MAXN][MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], id[MAXN], in[MAXN], cnt, top, scc, n;

void init() {
    cnt = top = scc = 0;
    for (int i = 0; i < n; ++i) {
        dfn[i] = in[i] = 0;
        G[i].clear();
    }
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    sta[top++] = u;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++scc;
        int v;
        do {
            v = sta[--top];
            in[v] = 0;
            id[v] = scc;
        } while (v != u);
    }
}

bool judge(double up) {
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 2 - i % 2; j < n; ++j) {
            if (mp[i][j] < up) {
                G[i].push_back(j^1);
                G[j].push_back(i^1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 0; i < n; i += 2) {
        if (id[i] == id[i + 1]) return 0;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        n *= 2;
        memset(in, 0, sizeof in);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mp[i][j] = mp[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            }
        }
        double l = 0, r = 5e4;
        while (r - l >= eps) {
            init();
            double mid = (r + l) / 2;
            //printf("%f %f\n", l, r);
            if (!judge(mid)) {
                r = mid;
            }
            else l = mid;
        }
        printf("%.2f\n", l / 2);
    }
    return 0;
}
