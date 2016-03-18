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
const int INF = 0x3f3f3f3f, MAXN = 1111;
char s1[MAXN], s2[MAXN];
int n, dp[MAXN][10][10];

int dfs(int d, int d1, int d2)
{
    int &ret = dp[d][d1][d2];
    if (ret >= 0) return ret;
    if (d == n) return ret = 0;
    ret = INF;
    int up = (s2[d] - d1 + 10) % 10;
    for (int i = 0; i <= up; ++i)
        for (int j = 0; j <= i; ++j)
            ret = min(ret, dfs(d + 1, (d2 + i) % 10, (s1[d + 2] + j) % 10) + up);
    int down = (d1 - s2[d] + 10) % 10;
    for (int i = 0; i <= down; ++i)
        for (int j = 0; j <= i; ++j)
            ret = min(ret, dfs(d +1, (d2 - i + 10)%10, (s1[d + 2] - j + 10)%10) + down);
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s%s", s1, s2))
    {
        n = strlen(s1);
        for (int i = 0; i < n; ++i)
        {
            s1[i] -= '0'; s2[i] -= '0';
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(0, s1[0],s1[1]));
    }
    return 0;
}
