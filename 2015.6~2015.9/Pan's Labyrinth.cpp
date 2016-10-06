#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 511;
double x[MAXN], y[MAXN], dis[MAXN][MAXN];

inline double geth(int a, int b, int c)
{
    if (x[a] == x[b]) return fabs(x[c] - x[a]);
    double kk = (y[a] - y[b]) / (x[a] - x[b]);
    return fabs(kk*(x[c] - x[a]) + y[a] - y[c]) / sqrt(1 + kk * kk);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", x + i, y + i);
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                double dx = x[i] - x[j], dy = y[i] - y[j];
                dis[i][j] = dis[j][i] = sqrt(dx * dx + dy * dy);
                //cout << i << ',' << j << ':' << dis[i][j] << endl;
            }
        double ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int node = 0;
            double mx = 0;
            for (int j = 0; j < n; ++j)
            {
                if (dis[i][j] > mx)
                {
                    node = j;
                    mx = dis[i][j];
                }
            }
            for (int k = 0; k < n; ++k)
            {
                if (k == i || k == node) continue;
                ans = max(ans, geth(k, node, i));
                ans = max(ans, geth(i, k, node));
                ans = max(ans, geth(node, k, i));
            }
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
