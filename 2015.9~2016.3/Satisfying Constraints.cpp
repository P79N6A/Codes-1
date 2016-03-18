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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

int n, m, k;
int x[1100], a[2][MAXN], num[2][MAXN], c[MAXN];
int vis[1100];
vector<pii> G[1100];

bool dfs(int u, int f) {
    vis[u] = f;
    bool flag = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        pii cur = G[u][i];
        int j = cur.first, sta = cur.second;
        if (vis[num[1 - sta][j]] == f) continue;
        if (!a[1 - sta][j] || (c[j] - a[sta][j] * x[num[sta][j]]) % a[1 - sta][j]) continue;
        x[num[1 - sta][j]] = (c[j] - a[sta][j] * x[num[sta][j]]) / a[1 - sta][j];
        if (dfs(num[1 - sta][j], flag)) return 1;
        flag = 1;
    }
    if (flag)
        return 0;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase; scanf("%d", &kase);
    while (kase --) {
        scanf("%d%d%d", &n, &m, &k);
        bool flag = 1;
        for (int i = 1; i <= n; ++i) G[i].clear(), x[i] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d%d", &a[0][i], &num[0][i], &a[1][i], &num[1][i], &c[i]);
            if (!a[0][i] && !a[1][i] && !c[i]) {
                flag = 0;
                continue;
            }
            else if (!a[0][i] && a[1][i] && (c[i] % a[1][i])) {
                flag = 0;
                continue;
            }
            else if (!a[1][i] && a[0][i] && (c[i] % a[0][i])) {
                flag = 0;
                continue;
            }
            G[num[0][i]].push_back(pii(i, 0));
            G[num[1][i]].push_back(pii(i, 1));
        }
        for (int i = 1; i <= n; ++i) {
            if (x[i]) continue;
            bool flag2 = 0;
            memset(vis, 0, sizeof(int)*(n + 4));
            for (int j = 1; j <= k; ++j) {
                x[i] = j;
                if (dfs(i, j)) {
                    flag2 = 1;
                    break;
                }
            }
            if (!flag2) {
                flag = 0;
                break;
            }
        }
        //for (int i = 1; i <= n; ++i) cout << x[i] << ' ';
        if (flag) {
            for (int i = 0; i < m; ++i) {
                if (a[0][i] * x[num[0][i]] + a[1][i] * x[num[1][i]] != c[i]) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
