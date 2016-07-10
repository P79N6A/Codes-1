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

set<int> G[MAXN];
int col[MAXN];
int vis[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
    while (m --) {
        scanf("%d%d", &u, &v);
        if (col[u] == col[v]) continue;
        G[col[u]].insert(col[v]);
        G[col[v]].insert(col[u]);
    }
    int ans = -1, ansc = 0;
    sort(col + 1, col + n + 1);
    int len = unique(col + 1, col + n + 1) - col;
    for (int i = 1; i <= len; ++i) {
        if ((int)G[col[i]].size() > ans) {
            ans = G[col[i]].size();
            ansc = col[i];
        }
    }
    printf("%d\n", ansc);
    return 0;
}
