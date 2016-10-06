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
const int MAXN = 1111;

char num[MAXN], ans[MAXN];
int dp[MAXN][12];

int my_min(int a, int b) {
    return num[a] <= num[b] ? a : b;
}

void init(int n) {
    for (int i = 0; i < n; ++i) dp[i][0] = i;
    for (int j = 1; j < 12; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            dp[i][j] = my_min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int getMin(int l, int r) {
    int k = log2(r - l + 1);
    return my_min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m;
    while (~scanf("%s%d", num, &m)) {
        int len = strlen(num);
        init(len);
        m = len - m;
        int cnt = 0, i = 0;
        while (m --) {
            i = getMin(i, len - m - 1);
            ans[cnt++] = num[i++];
        }
        ans[cnt] = 0;

        i = 0;
        while (ans[i] == '0') ++i;
        if (i == cnt) puts("0");
        else {
            for (; i < cnt; ++i) printf("%c", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
