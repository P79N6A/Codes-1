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

struct Square {
    int u, r, d, l;
}sq[30];
int par[30];
int mp[10][10];
bool vis[30];
int n, ed;

bool dfs(int p) {
    if (p == ed) {
        return 1;
    }

    bool nok[30] = {0};
    int x = p / n, y = p % n;
    for (int i = 0; i < ed; ++i) {
        if (vis[i]) continue;
        if (par[i] != -1 && nok[par[i]]) continue;
        if (x > 0 && sq[mp[x - 1][y]].d != sq[i].u) {
                if (par[i] == -1) nok[i] = 1;
                continue;
        }
        if (y > 0 && sq[mp[x][y - 1]].r != sq[i].l) {
                if (par[i] == -1) nok[i] = 1;
                continue;
        }
        mp[x][y] = i;
        vis[i] = 1;
        if (dfs(p + 1)) return 1;
        vis[i] = 0;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        ed = n * n;
        for (int i = 0; i < ed; ++i) {
            par[i] = -1;
            vis[i] = 0;
            scanf("%d%d%d%d", &sq[i].u, &sq[i].r, &sq[i].d, &sq[i].l);
        }
        for (int i = 0; i < ed; ++i) {
            for (int j = i + 1; j < ed; ++j) {
                if (par[j] == -1 && sq[i].u == sq[j].u && sq[i].r == sq[j].r
                    && sq[i].d == sq[j].d && sq[i].l == sq[j].l)
                    par[j] = i;
            }
        }

        if (kase) putchar('\n');
        if (dfs(0)) printf("Game %d: Possible\n", ++kase);
        else printf("Game %d: Impossible\n", ++kase);
    }
    return 0;
}
