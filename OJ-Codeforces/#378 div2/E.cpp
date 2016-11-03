#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

char s[MAXN];
ll ans[MAXN];
int pos[MAXN], len;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n;
    scanf("%d%s", &n, s + 1);
    // 从左往右，左边U个数一定小于右边D个数
    len = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'D') pos[++len] = i;
    }
    ll tol = 0;
    for (int i = 1; i <= len; ++i) {
        tol += (pos[i] - i) << 1;
        ans[i] = i + tol;
    }
    // 从右往左，右边D个数一定小于左边U个数
    len = 0;
    for (int i = n; i > 0; --i) {
        if (s[i] == 'U') pos[++len] = i;
    }
    tol = 0;
    for (int i = 1; i <= len; ++i) {
        int cur = n - i + 1;
        tol += (cur - pos[i]) << 1;
        ans[cur] = i + tol;
    }
    for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
    return 0;
}