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
const int MAXN = 1e3 + 11;
const int MAXNN = 1e5 + 111;

char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
int n, m, k, a, b, cnt[MAXNN];

int dfs(int x, int y, int flag)
{
    if (vis[x][y]) return cnt[vis[x][y]];
    vis[x][y] = flag;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (mp[nx][ny] == '*') ++cnt[flag];
        else dfs(nx, ny, flag);
    }
    return cnt[flag];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", &mp[i]);
    }
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d", &a, &b);
        --a, --b;
        cnt[i] = dfs(a, b, i);
        printf("%d\n", cnt[i]);
    }
    return 0;
}
