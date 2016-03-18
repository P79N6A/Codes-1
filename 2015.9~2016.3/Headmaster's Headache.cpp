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
const int MAXN = 151;

int s, m, n, dp[1 << 8][1 << 8][MAXN], sub[MAXN], cost[MAXN];

int dfs(int s1, int s2, int p)
{
    if (p == m + n) return s1 == (1 << s) - 1 ? 0 : INF;
    int &ret = dp[s1][s2][p];
    if (ret >= 0) return ret;
    ret = INF;
    if (p >= m)
        ret = dfs(s1, s2, p + 1);
    s1 |= (s2 & sub[p]);
    s2 |= sub[p];
    ret = min(ret, dfs(s1, s2, p + 1) + cost[p]);
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> s >> m >> n && s)
    {
        cin.get();
        string ss;
        int x;
        for (int i = 0; i < m + n; ++i)
        {
            getline(cin, ss);
            stringstream sss(ss);
            sss >> cost[i];
            while (sss >> x)
            {
                sub[i] |= 1 << (x - 1);
            }
        }

        memset(dp, -1, sizeof dp);
        cout << dfs(0, 0, 0) << '\n';
    }
    return 0;
}
