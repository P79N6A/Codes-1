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

vector<int> G[MAXN];
int matchl[MAXN], matchr[MAXN], c, r, n, x, y;
bool visx[MAXN], visy[MAXN];

bool dfs(int x)
{
    visx[x] = 1;
    for (int i = 0; i < G[x].size(); ++i)
    {
        int v = G[x][i];
        if (!visy[v])
        {
            visy[v] = 1;
            if (matchl[v] == -1 || dfs(matchl[v]))
            {
                matchl[v] = x;
                matchr[x] = v;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d%d", &r, &c, &n) && (c || r || n))
    {
        for (int i = 1; i <= r; ++i) G[i].clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
        }
        memset(matchl, -1, sizeof matchl);
        memset(matchr, -1, sizeof matchr);
        int ans = 0;
        for (int i = 1; i <= r; ++i)
        {
            memset(visy, 0, sizeof visy);
            if (dfs(i)) ++ans;
        }

        printf("%d", ans);
        memset(visx, 0, sizeof visx);
        memset(visy, 0, sizeof visy);
        for (int i = 1; i <= r; ++i)
        {
            if (matchr[i] == -1) dfs(i);
        }
        for (int i = 1; i <= r; ++i)
            if (!visx[i]) printf(" r%d", i);
        for (int i = 1; i <= c; ++i)
            if (visy[i]) printf(" c%d", i);
        printf("\n");
    }
    return 0;
}

