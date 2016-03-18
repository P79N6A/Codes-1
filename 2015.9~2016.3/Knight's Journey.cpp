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
const int MAXN = 31;

int p, q, ed;
int dir[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool mp[MAXN][MAXN];
pii ans[900];

bool dfs(int x, int y, int dep) {
    ans[dep] = pii(x, y);
    if (dep == ed) {
        for (int i = 1; i <= dep; ++i) printf("%c%d", 'A' + ans[i].second, ans[i].first + 1);
        return 1;
    }

    for (int i = 0; i < 8; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (0 <= nx && nx < p && 0 <= ny && ny < q && !mp[nx][ny]) {
            mp[nx][ny] = 1;
            if (dfs(nx, ny, dep + 1)) return 1;
            mp[nx][ny] = 0;
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d%d", &p, &q);
        ed = p * q;
        printf("Scenario #%d:\n", kase);
        memset(mp, 0, sizeof mp);
        mp[0][0] = 1;
        if (!dfs(0, 0, 1)) printf("impossible");
        printf("\n\n");
    }
    return 0;
}
