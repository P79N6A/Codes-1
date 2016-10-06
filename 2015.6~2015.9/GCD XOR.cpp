#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;
int ans[30000001];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    for (int c = 1; c <= 15000000; ++c)
    {
        for (int a = c * 2; a <= 30000000; a += c)
        {
            if (c == (a^(a - c)))
                ++ans[a];
        }
    }
    for (int i = 2; i <= 30000000; ++i)
        ans[i] += ans[i - 1];
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", kase, ans[n]);
    }
    return 0;
}
