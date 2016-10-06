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
const int MAXN = 611;

string dic[MAXN];
int dp[400];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int w, l;
    string s;
    cin >> w >> l >> s;
    for (int i = 0; i < w; ++i) cin >> dic[i];

    dp[l] = 0;
    for (int i = l - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + 1;
        for (int j = 0; j < w; ++j) {
            int len = dic[j].length();
            if (len <= l - i && dic[j][0] == s[i]) {
                int ps = i, pw = 0;
                while (ps < l) {
                    if (dic[j][pw] == s[ps++]) ++pw;
                    if (pw == len) {
                        dp[i] = min(dp[i], dp[ps] + ps - i - len);
                        break;
                    }
                }
            }
        }
    }

    cout << dp[0] << '\n';
    return 0;
}
