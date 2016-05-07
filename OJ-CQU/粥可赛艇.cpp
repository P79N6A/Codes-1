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

int dp[50][2][50][50], n, k;

int dfs(int road, int dir, int step, int change) {
    int &ret = dp[road][dir][step][change];
    if (ret >= 0) return ret;
    if (road == 1 && step == 2 * n && change == 2 * k - 1) return ret = 1;
    if (step >= 2 * n || change > 2 * k - 1) return ret = 0;
    ret = 0;
    if (dir == 0) {
        if (road > 1)
            ret += dfs(road - 1, dir, step + 1, change);
        ret += dfs(road + 1, 1, step + 1, change + 1);
    }
    else {
        ret += dfs(road + 1, dir, step + 1, change);
        if (road > 1)
            ret += dfs(road - 1, 0, step + 1, change + 1);
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(1, 1, 0, 0));
    }
    return 0;
}
