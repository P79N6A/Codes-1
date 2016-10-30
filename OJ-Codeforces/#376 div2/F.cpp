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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 4e5 + 111;

int a[MAXN];
ll cnt[MAXN];
ll sum[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    for (int i = 1; i <= 400000; ++i) {
        sum[i] = cnt[i] + sum[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= 2e5; ++i) {
        if (cnt[i]) {
            ll temp = 0;
            for (int j = i; j <= 2e5; j += i) {
                int l = j - 1, r = l + i;
                temp += (sum[r] - sum[l]) * j;
            }
            ans = max(ans, temp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
