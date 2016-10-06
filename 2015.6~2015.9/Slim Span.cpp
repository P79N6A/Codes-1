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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;
int u[MAXN], v[MAXN], w[MAXN], id[MAXN], n, m, p[111];

void init() {for (int i = 1; i <= n; ++i) p[i] = i;}

bool cmp(const int i, const int j) {return w[i] < w[j];}

int fnd(int x) {return p[x] == x ? x : p[x] = fnd(p[x]);}

bool ok()
{
    int tar = fnd(1);
    for (int i = 2; i <= n; ++i) if(fnd(i) != tar)
        return 0;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && (n||m))
    {
        for (int i = 0; i < m; ++i)
        {
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            u[i] = l, v[i] = r, w[i] = c, id[i] = i;
        }
        sort(id, id + m, cmp);
        int ans = INF;
        for (int l = 0; l < m; ++l)
        {
            init();
            for (int r = l; r < m; ++r)
            {
                int e = id[r];
                int x = fnd(u[e]), y = fnd(v[e]);
                if (x != y) p[x] = y;
                if (ok())
                {
                    ans = min(ans, w[id[r]] - w[id[l]]);
                    break;
                }
            }
        }
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
