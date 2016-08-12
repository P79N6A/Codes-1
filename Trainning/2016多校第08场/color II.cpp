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
#define uint unsigned int
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 19;

char mp[MAXN][MAXN];
int g[MAXN];
uint p[1 << MAXN];
uint dp[1 << MAXN];
bool vis[1 << MAXN];

inline void init() {
    p[1] = 233;
    for (int i = 2; i < (1 << 18); ++i) {
        p[i] = p[i - 1] * 233;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    init();
    while (t --) {
        scanf("%d", &n);
        int up = 1 << n;
        memset(vis, 0, sizeof vis);
        memset(g, 0, sizeof g);
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < n; ++j) {
                if (mp[i][j] == '1')
                    g[i] |= 1 << j;
            }
        }
        for (int i = 1; i < up; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    if (g[j] & i) {
                        vis[i] = 1;
                        break;
                    }
                }
            }
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int s = 1; s < up; ++s) {
            for (int s2 = s; s2; s2 = (s2 - 1) & s) {
                if (!vis[s2]) {
                    dp[s] = min(dp[s], dp[s ^ s2] + 1);
                }
            }
        }
        uint ans = 0;
        for (int i = 1; i < up; ++i) {
            ans += dp[i] * p[i];
        }
        printf("%u\n", ans);
    }
    return 0;
}
