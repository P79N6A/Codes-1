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
const int MAXN = 2e5 + 111;

int num[MAXN], lp[MAXN], rp[MAXN];

bool dfs(int l, int r)
{
    if (l >= r) return 1;
    int mid = (r - l + 1) / 2;
    for (int i = 0; i <= mid; ++i)
    {
        if (rp[l + i] > r && lp[l + i] < l) return dfs(l, l + i - 1) & dfs(l + i + 1, r);
        if (rp[r - i] > r && lp[r - i] < l) return dfs(l, r - i - 1) & dfs(r - i + 1, r);
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --)
    {
        map<int, int> pos;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]), lp[i] = 0, rp[i] = n + 1;

        for (int i = 1; i <= n; ++i)
        {
            lp[i] = pos[num[i]], rp[lp[i]] = i;
            pos[num[i]] = i;
        }

        if (!dfs(1, n)) printf("boring\n");
        else printf("non-boring\n");
    }
    return 0;
}
