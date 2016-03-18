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
const int MAXN = (1 << 20) + 11;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}

int day[22], dp[MAXN][8], k;

int dfs(int sta, int lef)
{
    int &ret = dp[sta][lef];
    if (!sta) return 0;
    if (~ret) return ret;
    ret = INF;
    for (int i = 0; i < k; ++i)
    {
        if (sta >> i & 1)
        {
            if (day[i] > lef)
                ret = min(ret, dfs(sta^(1 << i), day[i] - lef - 1) + day[i] - lef);
            else
                ret = min(ret, dfs(sta^(1 << i), 0) + 1);
        }
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scan_d(t);
    while (t --)
    {
        scan_d(k);
        for (int i = 0; i < k; ++i) scan_d(day[i]);
        memset(dp, -1, sizeof dp);
        cout << dfs((1 << k) - 1, 0) << '\n';
    }
    return 0;
}
