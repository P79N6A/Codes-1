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
const int MAXN = 1e5 + 111;

struct City{
    int x, id;
    bool operator < (const City& t)const
    {
        return x < t.x;
    }
}city[MAXN];

int hashId[MAXN], near[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, l, r;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &city[i].x), city[i].id = i;
        sort(city, city + n);
        for (int i = 1; i <= n; ++i) hashId[city[i].id] = i, near[i] = 0;
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d", &l, &r);
            l = hashId[l], r = hashId[r];
            if (l > r) swap(l, r);
            near[r] = max(near[r], l);
        }
        int ans = 0, mx = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (near[i] >= mx)
            {
                ans += city[i].x - city[near[i]].x;
                mx = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
