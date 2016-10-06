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
double mp[MAXN][MAXN];
bool vis[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a, b, kase = 0;
    while(cin >> a >> b && (a || b))
    {
        int up = 0;
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 101; ++j)
                mp[i][j] = INF;
        memset(vis, 0, sizeof vis);
        mp[a][b] = 1;
        vis[a] = vis[b] = 1;
        //cout << a << ',' << b <<endl;
        up = max(max(a, b), up);
        while (cin >> a >> b && (a || b))
        {
            mp[a][b] = 1;
            vis[a] = vis[b] = 1;
            up = max(max(a, b), up);
        }
        for (int i = 1; i <= up; ++i)
            for (int j = 1; j <= up; ++j)
                for (int k = 1; k <= up; ++k)
                {
                    mp[j][k] = min(mp[j][k], mp[j][i] + mp[i][k]);
                }
        double total = 0, cnt = 0;
        for (int i = 1; i <= up; ++i)
            for (int j = 1; j <= up; ++j)
            {
                if (i == j) continue;
                if (vis[i] && vis[j])
                {
                    total += mp[i][j];
                    ++cnt;
                }
            }
        printf("Case %d: average length between pages = %.3f clicks\n", ++kase, total / cnt);
    }
    return 0;
}

