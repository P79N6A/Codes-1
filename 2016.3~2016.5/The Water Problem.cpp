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
const int MAXN = 1e4 + 111;

int dp[MAXN][20];

void init(int n) {
    for (int i = 1; i < 12; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            dp[j][i] = max(dp[j + (1 << (i - 1))][i - 1], dp[j][i - 1]);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, q; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &dp[i][0]);
        }
        init(n);

        scanf("%d", &q);
        int l, r;
        while (q --) {
            scanf("%d%d", &l, &r);
            int x = 0;
            if (r != l) x = log2(r - l);
            printf("%d\n", max(dp[l][x], dp[r - (1 << x) + 1][x]));
        }
    }
    return 0;
}
