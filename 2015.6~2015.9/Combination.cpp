#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
struct N{
    int p, r, id;
}a[1111];
bool vis[1111];

bool cmp1(N a, N b)
{
    return a.p > b.p;
}

bool cmp2(N a, N b)
{
    return a.r > b.r;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].p >> a[i].r, a[i].id = i;
    sort(a, a + n, cmp2);
    int rnd = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].r < 1) break;
        rnd += a[i].r - 1;
        ans += a[i].p;
        vis[a[i].id] = 1;
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < n; ++i)
    {
        if (!vis[a[i].id])
        {
            ans += a[i].p;
            --rnd;
            if (rnd == 0) break;
        }
    }
    cout << ans << '\n';
	return 0;
}

