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
#define si short
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 5e3 + 100;

si mmin(si a, si b) {
    return a < b ? a : b;
}

si dp[MAXN][MAXN];
char s[MAXN];

si dfs(si l, si r) {
    si &ret = dp[l][r];
    if (ret >= 0) return ret;
    if (l + 1 == r) return ret = (s[l] != s[r]);
    if (l == r) return ret = 0;

    if (s[l] == s[r]) ret = dfs(l + 1, r - 1);
    else ret = mmin(dfs(l + 1, r), dfs(l, r - 1)) + 1;

    return ret;
}

int main()
{
    int n;
    while (~scanf("%d%s", &n, s)){
        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(0, n - 1));
    }
    return 0;
}
