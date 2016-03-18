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
const int MAXN = 1e5 + 111;

int Ma[MAXN * 2], h[MAXN];
int Mp[MAXN];
ll ans;

void Manacher(int s[], int len)
{
    int l = 0;
    Ma[l++] = 1, Ma[l++] = 0;
    for (int i = 0; i < len; ++i)
    {
        Ma[l++] = s[i];
        Ma[l++] = 0;
    }
    Ma[l] = -1;

    int mx = 0, id = 0;

    for (int i = 0; i < l; ++i)
    {
        Mp[i] = mx > i ? min(mx - i, Mp[id * 2 - i]) : 1;
        while (1)
        {
            int lef = i - Mp[i], rit = i + Mp[i];
            if (Ma[lef] != Ma[rit]) break;
            if (Ma[lef] == 0 || Ma[lef] <= Ma[lef + 2])
                ++Mp[i];
            else break;
        }

        ans = max(ans, (ll)Mp[i] - 1);

        if (i + Mp[i] > mx)
        {
            mx = i + Mp[i];
            id = i;
        }
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
        ans = 0;
        Manacher(h, n);
        printf("%I64d\n", ans);
    }
    return 0;
}
