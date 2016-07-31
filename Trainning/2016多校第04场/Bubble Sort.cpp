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

int a[MAXN], r[MAXN];
int sum[MAXN], n;

int lowbit(int x) {return x & (-x);}
void add(int x, int val) {
    while (x <= n) {
        sum[x] += val;
        x += lowbit(x);
    }
}

int get(int x) {
    int ret = 0;
    while (x > 0) {
        ret += sum[x];
        x -= lowbit(x);
    }
    return ret;
}

int ans[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum[i] = 0;
        for (int i = n; i >= 1; --i) {
            r[i] = get(a[i]);
            add(a[i], 1);
        }
        printf("Case #%d:", kase);
        for (int i = 1; i <= n; ++i) {
            ans[a[i]] = r[i] + i - min(i, a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            printf(" %d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
