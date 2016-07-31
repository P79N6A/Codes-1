/*
  存储以点x为区间右值的gcd值个数，然后更新
 */
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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int a[MAXN];
int gcd[MAXN][30];
map<int, ll> query;

void init(int n)
{
    query.clear();
    for(int i = 1; i <= n;i++)
    {
        gcd[i][0] = a[i];
    }
    int up = log2(n);
    for(int j = 1; j <= up;j++)
        for(int i = 1;i + (1<<j) -1 <= n;i++)
            gcd[i][j] = __gcd(gcd[i][j-1],gcd[i+(1<<(j-1))][j-1]);
    map<int, ll> mp[2];
    ++mp[0][a[1]];
    ++query[a[1]];
    int cur = 0;
    map<int, ll>::iterator it;
    for (int i = 2; i <= n; ++i) {
        int v = 1 - cur;
        ++mp[v][a[i]];
        for (it = mp[cur].begin(); it != mp[cur].end(); ++it) {
            mp[v][__gcd(a[i], (*it).first)] += (*it).second;
        }
        for (it = mp[v].begin(); it != mp[v].end(); ++it) {
            query[(*it).first] += (*it).second;
        }
        mp[cur].clear();
        cur = 1 - cur;
    }
}

int rmq(int x,int y)
{
    int k = log2(y-x+1);
    return __gcd(gcd[x][k],gcd[y-(1<<k)+1][k]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    for (int kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        init(n);
        int q; scanf("%d", &q);
        int l, r;
        printf("Case #%d:\n", kase);
        while (q --) {
            scanf("%d%d", &l, &r);
            int ans = rmq(l, r);
            printf("%d %lld\n", ans, query[ans]);
        }
    }
    return 0;
}
