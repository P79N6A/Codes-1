/*
  总的可能 - 四种重复的可能
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
const int MAXN = 5e4 + 111;

int a[MAXN], all[MAXN];
ll lg[MAXN], rg[MAXN], ls[MAXN], rs[MAXN];
int sum[MAXN], len;

int get(int x) {
    int ret = 0;
    while (x > 0) {
        ret += sum[x];
        x -= x & (-x);
    }
    return ret;
}

void add(int x) {
    while (x <= len) {
        ++sum[x];
        x += x & (-x);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            all[i] = a[i];
        }
        sort(all + 1, all + 1 + n);
        len = unique(all + 1, all + 1 + n) - all - 1;
        for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(all + 1, all + 1 + len, a[i]) - all;
        }
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= n; ++i) {
            lg[i] = get(len) - get(a[i]);
            ls[i] = get(a[i] - 1);
            add(a[i]);
        }
        ll ta = 0, tb = 0;
        memset(sum, 0, sizeof sum);
        for (int i = n; i >= 1; --i) {
            rg[i] = get(len) - get(a[i]);
            rs[i] = get(a[i] - 1);
            ta += rg[i];
            tb += rs[i];
            add(a[i]);
        }
        ll ans = ta * tb;
        for (int i = 1; i <= n; ++i) {
            ans -= rg[i] * rs[i];
            ans -= ls[i] * rs[i];
            ans -= lg[i] * rg[i];
            ans -= ls[i] * lg[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
