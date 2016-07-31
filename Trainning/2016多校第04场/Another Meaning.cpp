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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int MOD = 1000000007;

char s[MAXN], p[MAXN];
int dp[MAXN];
int nxt[MAXN];

void getNext(int len) {
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < len) {
        while (~j && p[i] != p[j]) j = nxt[j];
        nxt[++i] = ++j;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    for (int kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%s%s", s, p);
        int lens = strlen(s), lenp = strlen(p);
        getNext(lenp);
        dp[0] = 1;
        int i = 0, j = 0;
        while (i < lens) {
            while (~j && s[i] != p[j]) j = nxt[j];
            ++i, ++j;
            dp[i] = dp[i - 1];
            if (j >= lenp) {
                dp[i] = (dp[i] + dp[i - lenp]) % MOD;
                j = nxt[j];
            }
        }
        printf("Case #%d: %d\n", kase, dp[lens]);
    }
    return 0;
}
