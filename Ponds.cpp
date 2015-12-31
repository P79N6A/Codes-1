#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

int p[MAXN], ran[MAXN], e[MAXN], cnt[MAXN];
vector<int> G[MAXN];
ll v[MAXN], sum[MAXN];

void dfs(int x)
{
    --e[x];
    for (int i = 0; i < G[x].size(); ++i)
    {
        int temp = G[x][i];
        --e[temp];
        if (e[temp] == 1) dfs(temp);
    }
}

int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (ran[x] > ran[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (ran[x] == ran[y]) ++ran[y];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase; scanf("%d", &kase);
    while (kase --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i; ran[i] = 0; e[i] = 0; cnt[i] = 0; sum[i] = 0;
            G[i].clear();
            scanf("%lld", &v[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b); ++e[a];
            G[b].push_back(a); ++e[b];
            unite(a, b);
        }

        for (int i = 1; i <= n; ++i) if (e[i] == 1) dfs(i);

        for (int i = 1; i <= n; ++i)
        {
            if (e[i] > 1)
            {
                int x = find(i);
                ++cnt[x];
                sum[x] += v[i];
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i] % 2)
            {
                ans += sum[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
