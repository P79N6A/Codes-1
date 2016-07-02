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
int col[MAXN];
bool has[MAXN];

bool dfs(int u, int flag) {
    col[u] = flag;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!col[v]) {
            if (!dfs(v, 3 - flag)) return 0;
        }
        else if (col[v] == col[u]) return 0;
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    while (m --) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        has[u] = has[v] = 1;
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
        if (has[i] && !col[i] && !dfs(i, 1)) {
            ok = 0;
            break;
        }
    }
    if (!ok) puts("-1");
    else {
        vector<int> ans1, ans2;
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 1) ans1.push_back(i);
            else if (col[i] == 2) ans2.push_back(i);
        }
        printf("%d\n", ans1.size());
        for (int i = 0; i < ans1.size(); ++i) {
            printf("%d", ans1[i]);
            if (i != ans1.size() - 1) putchar(' ' );
            else putchar('\n');
        }
        printf("%d\n", ans2.size());
        for (int i = 0; i < ans2.size(); ++i) {
            printf("%d", ans2[i]);
            if (i != ans2.size() - 1) putchar(' ' );
            else putchar('\n');
        }
    }
    return 0;
}
