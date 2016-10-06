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
const int MAXN = 311;

int mp[MAXN][MAXN];
int a[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, cnt;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) mp[i][j] = INF;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", a + j);
        }
        for (int j = 0; j < cnt; ++j) {
            for (int k = j + 1; k < cnt; ++k) {
                mp[a[j]][a[k]] = mp[a[k]][a[j]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) mp[i][i] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mp[j][i] == INF) continue;
            for (int k = 1; k <= n; ++k) {
                if (mp[i][k] == INF) continue;
                mp[j][k] = min(mp[j][k], mp[j][i] + mp[i][k]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
            sum += mp[i][j];
        if (sum < ans) ans = sum;
    }
    --n;
    printf("%d\n", ans * 100 / n);
    return 0;
}
