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

const int INF = 0x7f7f7f7f;
const int MAXN = 50;

int a[400], m;
int dp[MAXN][MAXN][MAXN][MAXN];
int num[5];

int dfs(int p, int num1, int num2, int num3, int num4) {
    int &ret = dp[num1][num2][num3][num4];
    if (ret >= 0) return ret;
    ret = 0;
    if (num1 < num[1])
        ret = max(dfs(p - 1, num1 + 1, num2, num3, num4) + a[p], ret);
    if (num2 < num[2])
        ret = max(dfs(p - 2, num1, num2 + 1, num3, num4) + a[p], ret);
    if (num3 < num[3])
        ret = max(dfs(p - 3, num1, num2, num3 + 1, num4) + a[p], ret);
    if (num4 < num[4])
        ret = max(dfs(p - 4, num1, num2, num3, num4 + 1) + a[p], ret);
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, b; scanf("%d", &t);
    while (t --) {
        memset(num, 0, sizeof num);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &b);
            ++num[b];
        }
        memset(dp, -1, sizeof dp);
        dp[num[1]][num[2]][num[3]][num[4]] = a[1];
        printf("%d\n", dfs(n, 0, 0, 0, 0));
    }
    return 0;
}
