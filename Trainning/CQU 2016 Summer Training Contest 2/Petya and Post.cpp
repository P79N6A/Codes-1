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

ll a[MAXN], dis[MAXN];
ll record[MAXN];
int ans[MAXN * 2], cnt;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%I64d", &dis[i]);
    ll mi = 1e15, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i) sum += a[i];
        record[i] = sum;
        sum -= dis[i];
        mi = min(mi, sum);
    }
    record[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= -mi + record[i]) {
            ans[cnt++] = i + 1;
        }
    }

    mi = 1e15, sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) sum += a[i];
        record[i] = sum;
        sum -= dis[(i - 1 + n) % n];
        mi = min(mi, sum);
    }
    record[n - 1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= -mi + record[i]) {
            ans[cnt++] = i + 1;
        }
    }
    sort(ans, ans + cnt);
    cnt = unique(ans, ans + cnt) - ans;
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) printf("%d ", ans[i]);
    return 0;
}
