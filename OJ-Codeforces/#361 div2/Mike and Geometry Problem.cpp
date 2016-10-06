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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;
const int mod = 1e9 + 7;

vector<pii> vec;
ll fac[MAXN];

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

ll quick_pow(ll x, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        p /= 2;
    }
    return ret;
}

int c(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * quick_pow(fac[n - m] * fac[m] % mod, mod - 2) % mod;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k, n, l, r;
    scanf("%d%d", &n, &k);
    init(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        vec.push_back(make_pair(l - 1, 1));
        vec.push_back(make_pair(r, -1));
    }
    sort(vec.begin(), vec.end());
    ll cnt = 0; // 上一个点出现的次数
    ll last = vec[0].first;
    ll ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        pii cur = vec[i];
        //pr(cnt)
        //pr(c(cnt, k))
        //pr(c(cnt, k) * (cur.first - last))
        ans = (ans + c(cnt, k) * (cur.first - last) % mod) % mod;
        last = cur.first;
        cnt += cur.second;
    }
    printf("%I64d\n", ans);
    return 0;
}
