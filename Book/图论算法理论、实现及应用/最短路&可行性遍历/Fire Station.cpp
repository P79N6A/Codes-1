/* 题意：
 * 添加一个消防站，使得所有房子到它最近的消防站的距离的最大值减少(PS:读边直到文件尾)
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e2 + 111;

int fire[MAXN];
int mp[MAXN][MAXN];
int dis[MAXN]; // 房子i到它最近消防站的距离
bool is[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &fire[i]);
        is[fire[i]] = 1;
    }
    sort(fire, fire + n);
    n = unique(fire, fire + n) - fire;
    memset(mp, 0x3f, sizeof mp);

    // ZZ ?
    while (~scanf("%d%d%d", &u, &v, &w)) {
        mp[u][v] = mp[v][u] = min(mp[u][v], w);
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= m; ++k) {
                mp[j][k] = min(mp[j][k], mp[j][i] + mp[i][k]);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= m; ++i) {
        if (is[i]) continue;
        int mi = INF;
        for (int j = 0; j < n; ++j) {
            mi = min(mi, mp[i][fire[j]]);
        }
        dis[i] = mi;
        mx = max(mx, mi);
    }
    int ans = 1;
    // 枚举新消防站
    for (int i = 1; i <= m; ++i) {
        if (is[i]) continue;
        int temp = 0;
        for (int j = 1; j <= m; ++j) {
            if (is[j] || i == j) continue;
            temp = max(temp, min(mp[i][j], dis[j]));
        }
        if (temp < mx) {
            ans = i;
            mx = temp;
        }
    }
    printf("%d\n", ans);
    return 0;
}
