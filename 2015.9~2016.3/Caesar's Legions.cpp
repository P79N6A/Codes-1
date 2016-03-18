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

const int MOD = 1e8;

int n1, n2, k1, k2;
int dp[300][111][2][20];

int dfs(int n, int num, int sta, int len) {
    //cout << n << '-' << num << '-' << sta << '-' << len << '\n';
    int &x = dp[n][num][sta][len];
    //if (x != -1) return x;
    x = 0;
    if (n > n1 + n2) return 0;
    if (n == n1 + n2 && num == n1) return x = 1;

    if (sta == 0) {
        if (num + 1 <= n1 && len + 1 <= k1)
            x += dfs(n + 1, num + 1, 0, len + 1);
        if (n + 1 - num <= n2)
            x += dfs(n + 1, num, 1, 1);
    }
    else {
        if (num + 1 <= n1)
            x += dfs(n + 1, num + 1, 0, 1);
        if (len + 1 <= k2 && n + 1 - num <= n2)
            x += dfs(n + 1, num, 1, len + 1);
    }
    return x % MOD;
}

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0, 0, 0) << '\n';
    return 0;
}
