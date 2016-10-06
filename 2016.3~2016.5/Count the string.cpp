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
const int MAXN = 2e5 + 111;

int nxt[MAXN], dp[MAXN]; // 到i为止包含的前缀个数
char p[MAXN];

void getNext(int len) {
    nxt[1] = 0;
    int k = 0;
    for (int i = 2; i <= len; ++i) {
        while (k && p[k + 1] != p[i]) k = nxt[k];
        nxt[i] = (p[k + 1] == p[i] ?  ++k : 0);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        scanf("%s", p + 1);
        getNext(n);
        int sum = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1;
            dp[i] += dp[nxt[i]];
            dp[i] %= 10007;
            sum += dp[i];
            sum %= 10007;
        }
        printf("%d\n", sum);
    }
    return 0;
}
