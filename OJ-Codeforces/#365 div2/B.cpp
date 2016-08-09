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

ll val[MAXN];
bool is[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, x;
    scanf("%d%d", &n, &k);
    ll ans = 0;
    ll sum = 0;
    ll sumcap = 0;
    for (int i = 0; i < n; ++i) scanf("%I64d", &val[i]), sum += val[i];
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        --x;
        is[x] = 1;
        sumcap += val[x];
    }
    ll ex = 0;
    for (int i = 0; i < n; ++i) {
        ans += val[i] * val[(i + 1) % n];
    }
    for (int i = 0; i < n; ++i) {
        if (is[i]) {
            ex += val[i] * (sumcap - val[i]);
            int last = (i - 1 + n) % n, nxt = (i + 1) % n;
            ll mul = sum - sumcap;
            if (!is[nxt]) mul -= val[nxt];
            if (!is[last]) mul -= val[last];
            ans += mul * val[i];
            if (is[nxt]) ans -= val[i] * val[nxt];
        }
    }
    printf("%I64d\n", ans + ex / (ll)2);
    return 0;
}
