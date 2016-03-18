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
using namespace std;

const int MAXN = 1e3 + 111;

int dp[MAXN][50];
int t[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, w; scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", t + i);
        t[i] -= 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (j % 2)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + t[i];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + !t[i];
        }
    }

    printf("%d\n", dp[n][w]);
    return 0;
}
