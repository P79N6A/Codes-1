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
const int INF = 0x3f3f3f3f, MAXN = 111;
int mp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int c, s, q, kase = 0;
    while (cin >> c >> s >> q && (c||s||q))
    {
        memset(mp, 0x3f, sizeof mp);
        int a, b, cc;
        for (int i = 0; i < s; ++i)
        {
            scanf("%d%d%d", &a, &b, &cc);
            mp[a][b] = mp[b][a] = cc;
        }
        for (int i = 1; i <= c; ++i)
            for (int j = 1; j <= c; ++j)
                for (int k = 1; k <= c; ++k)
                {
                    mp[j][k] = min(mp[j][k], max(mp[j][i], mp[i][k]));
                }
        if (kase) cout << '\n';
        cout << "Case #" << ++kase << '\n';
        for (int i = 0; i < q; ++i)
        {
            scanf("%d%d", &a, &b);
            if (mp[a][b] == INF) cout << "no path\n";
            else cout << mp[a][b] << '\n';
        }
    }
    return 0;
}
