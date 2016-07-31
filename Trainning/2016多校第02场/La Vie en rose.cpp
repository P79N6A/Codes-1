/*
  每一次将可行的状态记录下来，也就是
  代表字符串的位置置为1，然后如果下次
  也是可行的，就可以由这个转移过来
  比如s: abcbac    p: abc
  第一次：       第二次：     第三次：
  左换：000000     000010       000000
  不换：100010     010000       001001
  右换：010100     000001       000000
 */
#include<algorithm>
#include<bitset>
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

char s[MAXN], p[5555];
bitset<MAXN> dp[2][3];
bitset<MAXN> pos[26];

void debug(int u, int n) {
    for (int j = 1; j <= n; ++j) cout << dp[u][0][j];
    cout << '\n';
    for (int j = 1; j <= n; ++j) cout << dp[u][1][j];
    cout << '\n';
    for (int j = 1; j <= n; ++j) cout << dp[u][2][j];
    cout << "\n\n";
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%s%s", &n, &m, s + 1, p + 1);
        for (int i = 0; i < 26; ++i) {
            pos[i].reset();
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            pos[s[i] - 'a'][i] = 1;
            dp[0][0][i] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            int u = i % 2, v = u ^ 1;
            for (int j = 0; j < 3; ++j) dp[u][j].reset();
            int pre = p[i - 1] - 'a', cur = p[i] - 'a', nxt = p[i + 1] - 'a';

            // dp[u][0][i] = dp[v][2][i - 1];
            if (i > 1)
                dp[u][0] = (dp[v][2] << 1) & pos[pre];

            // dp[u][1][i] = (dp[v][1][i - 1] | dp[v][0][i - 1]);
            dp[u][1] = ((dp[v][1] | dp[v][0]) << 1) & pos[cur];

            // dp[u][2][i] = (dp[v][1][i - 1] | dp[v][0][i - 1]);
            if (i < m)
                dp[u][2] = ((dp[v][1] | dp[v][0]) << 1) & pos[nxt];

            //debug(u, n);
        }
        int last = m % 2;
        for (int i = 1; i <= n; ++i) {
            bool flag = 0;
            int x = i + m - 1;
            if (x <= n)
                for (int j = 0; j < 2; ++j) flag |= dp[last][j][x];
            if (flag) putchar('1');
            else putchar('0');
        }
        putchar('\n');
    }
    return 0;
}
