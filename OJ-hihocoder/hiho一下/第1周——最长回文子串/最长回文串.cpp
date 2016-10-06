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
const int MAXN = 1e6 + 111;

char s[MAXN], str[MAXN << 1];
int dp[MAXN << 1];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%s", s);
        int len = strlen(s), cnt = 0;
        str[cnt++] = '$';
        for (int i = 0; i < len; ++i) {
            str[cnt++] = '#';
            str[cnt++] = s[i];
        }
        str[cnt++] = '#';
        str[cnt++] = 0;

        int mx = 0, id = 0, ans = 0;
        for (int i = 0; i < cnt; ++i) {
            dp[i] = mx > i ? min(dp[2 * id - i], mx - i) : 1;
            while (str[i + dp[i]] == str[i - dp[i]]) ++dp[i];
            ans = max(ans, dp[i] - 1);
            if (dp[i] + i > mx) {
                mx = dp[i] + i;
                id = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
