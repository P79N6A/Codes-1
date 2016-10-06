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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

double x[MAXN], y[MAXN];
bool rep[MAXN];
int p[MAXN], rnk[MAXN];
vector<int> G[MAXN];

int find(int a){
    return a == p[a] ? a : p[a] = find(p[a]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (rnk[y] > rnk[x])
        p[x] = p[y];
    else {
        p[y] = p[x];
        if (rnk[x] == rnk[y]) ++rnk[x];
    }
    return 1;
}

double getdis(int a, int b) {
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx * dx + dy * dy);
}

void dfs(int a) {
    for (int i = 0; i < G[a].size(); ++i) {
        int v = G[a][i];
        if (rep[v] && unite(a, v))
            dfs(v);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    double d;
    scanf("%d%lf", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &x[i], &y[i]);
        p[i] = i;
        rnk[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (getdis(i, j) <= d) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    char op[2];
    int a, b;
    while (~scanf("%s", op)) {
        if (op[0] == 'O') {
            scanf("%d", &a);
            rep[a] = 1;
            dfs(a);
        }
        else {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
