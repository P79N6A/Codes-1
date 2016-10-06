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

int par[MAXN], rnk[MAXN], sum[MAXN];

vector<int> fib;

void init()
{
    int a = 0, b = 1, c;
    fib.push_back(0), fib.push_back(1);
    while (1)
    {
        c = a + b;
        fib.push_back(c);
        if (c > 1e9) break;
        a = b;
        b = c;
    }
}

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
    {
        if (rnk[x] > rnk[y])
        {
            par[y] = x;
            sum[x] += sum[y];
        }
        else
        {
            par[x] = y;
            sum[y] += sum[x];
            if (rnk[x] == rnk[y]) ++rnk[x];
        }
    }
}

int main()
{
    init();
    int n, m, u, v;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &sum[i]);
            par[i] = i, rnk[i] = 0;
            int x = lower_bound(fib.begin(), fib.end(), sum[i]) - fib.begin();
            if (fib[x] == sum[i]) sum[i] = 1;
            else sum[i] = 0;
        }

        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            unite(u, v);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = max(ans, sum[i]);
        printf("%d\n", ans);
    }
    return 0;
}
