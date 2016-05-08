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
bool vis[30], nok[30];
int n, ed;

bool dfs(int x, int y, int num) {
    if (num == ed) {
        return 1;
    }
    int nx = x, ny = y;
    if (ny + 1 == n) ++nx, ny = 0;
    else ++ny;

    memset(nok, 0, sizeof nok);
    for (int i = 0; i < ed; ++i) {
        if (vis[i]) continue;
        if (nok[par[i]]) continue;
        if (nx > 0 && sq[mp[nx - 1][ny]].d != sq[i].u) {
                if (par[i] == -1) nok[i] = 1;
                continue;
        }
        if (ny > 0 && sq[mp[nx][ny - 1]].r != sq[i].l) {
                if (par[i] == -1) nok[i] = 1;
                continue;
        }
        mp[nx][ny] = i;
        vis[i] = 1;
        if (dfs(nx, ny, num + 1)) return 1;
        vis[i] = 0;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "w", stdout);
    #endif
    cout << 1000 << '\n';
    for (int i = 1; i <= 1000; ++i) cout << i << '\n';
    return 0;
}
