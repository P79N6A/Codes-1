/*
  统计每个数字到对某一位的贡献程度
 */
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
const int mod = 1e9 + 7;

char s[MAXN];
ll a[MAXN], l[MAXN], r[MAXN], lsum[MAXN], rsum[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d%s", &n, s + 1)) {
        for (int i = 1; i <= n; ++i) {
            a[i] = s[i] - '0';
        }
        for (int i = 1; i <= n; ++i) {
            l[i] = (l[i - 1] + a[i]) % mod;
            r[i] = (r[i - 1] + a[n - i + 1]) % mod;
            lsum[i] = (lsum[i - 1] + a[i] * i) % mod;
            rsum[i] = (rsum[i - 1] + a[n - i + 1] * i) % mod;
        }
        ll ans = 0, temp;
        for (ll i = 1; i <= n; ++i) {
            ll lef = n - i + 1;
            temp = a[i] * (i * (i - 1) / 2 + lef * (lef - 1) / 2) % mod;
            temp = (temp + a[i] * min(i, lef)) % mod;
            if (i >= lef) {
                temp = (temp + rsum[lef - 1] + lsum[lef - 1]) % mod;
                temp = (temp + (l[i - 1] - l[lef - 1]) * lef) % mod;
            }
            else {
                temp = (temp + rsum[i - 1] + lsum[i - 1]) % mod;
                temp = (temp + (r[lef - 1] - r[i - 1]) * i) % mod;
            }
            ans = (ans * 10 + temp) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
