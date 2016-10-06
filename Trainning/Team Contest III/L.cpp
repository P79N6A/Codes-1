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
const int MAXN = 111;

int up[MAXN][MAXN], down[MAXN][MAXN], lef[MAXN][MAXN], rig[MAXN][MAXN];
int a[MAXN][MAXN];

int get(int x, int y) {
    int base = a[x][y];
    return (base > up[x - 1][y]) + (base > down[x + 1][y]) + (base > lef[x][y - 1]) + (base > rig[x][y + 1]);
}

int main()
{
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            lef[i][j] = max(a[i][j], lef[i][j - 1]);
        }
        for (int j = m; j >= 1; --j) {
            rig[i][j] = max(a[i][j], rig[i][j + 1]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            up[j][i] = max(a[j][i], up[j - 1][i]);
        }
        for (int j = n; j >= 1; --j) {
            down[j][i] = max(a[j][i], down[j + 1][i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += get(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}
