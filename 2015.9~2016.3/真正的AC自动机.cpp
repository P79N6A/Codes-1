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
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;
typedef pair<int, int> pii;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct ACM
{
    int a, c, id;
    bool operator < (const ACM& t)const
    {
        return a > t.a;
    }
}p[MAXN], s[MAXN];

int ans[MAXN], n, m, l;

bool check(int x)
{
    set<pii> pq;
    int cost = 0;
    for (int i = 1, j = 1; i <= m;)
    {
        while (j <= n && p[j].a >= s[i].a)
        {
            pq.insert(pii(p[j].c, p[j].id));
            ++j;
        }
        if (!pq.size()) return 0;
        cost += pq.begin()->first;
        if (cost > l) return 0;
        int temp = x, id = pq.begin()->second;
        pq.erase(pq.begin());
        while (temp-- && i <= m) ans[s[i++].id] = id;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d%d",&n, &m, &l))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i].a), p[i].id = i;
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i].c);
        for (int i = 1; i <= m; ++i) scanf("%d", &s[i].a), s[i].id = i;
        sort(p + 1, p + n + 1);
        sort(s + 1, s + m + 1);

        int l = 0, r = m;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m)) r = m - 1;
            else l = m + 1;
        }

        if (check(l))
        {
            printf("Good Luck\n");
            for (int i = 1; i <= m; ++i) printf("%d%c", ans[i], " \n"[i == m]);
        }
        else printf("Do it yourself\n");
    }
    return 0;
}
