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
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;

int c[111], t[111], n;
double dp[MAXN];

double dfs(int f) {
    double &ret = dp[f];
    if (ret > 0) return ret;

    for (int i = 1; i <= n; ++i) {
        if (f > c[i]) ret += 1.0 / n * t[i];
        else ret += 1.0/n + dfs(f + c[i]) / n;
    }

    return ret;
}

int main()
{
    int f;
    while (~scanf("%d%d", &n, &f)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &c[i]);
            t[i] = (1.0 + sqrt(5.0)) / 2.0 * c[i] * c[i];
        }
        memset(dp, 0, sizeof dp);
        printf("%.3f\n", dfs(f));
    }
    return 0;
}
