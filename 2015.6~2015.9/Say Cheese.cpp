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
double dis[MAXN][MAXN];
struct N{
    double x, y, z, r;
}node[MAXN];

double getdis(int i, int j)
{
    N &a = node[i], &b = node[j];
    double ret = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    return max(0.0 ,ret - a.r - b.r);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, kase = 0;
    while (cin >> n && n != -1)
    {
        for (int i = 1; i <= n; ++i)
        {
            cin >> node[i].x >> node[i].y >> node[i].z >> node[i].r;
        }
        for (int i = n + 1; i <= n + 2; ++i)
        {
            cin >> node[i].x >> node[i].y >> node[i].z;
            node[i].r = 0;
        }
        n += 2;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)if(i!=j)
            {
                dis[i][j] = dis[j][i] = getdis(i,j);
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                {
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
        printf("Cheese %d: Travel time = %.0f sec\n", ++kase, dis[n - 1][n]*10);
    }
    return 0;
}

