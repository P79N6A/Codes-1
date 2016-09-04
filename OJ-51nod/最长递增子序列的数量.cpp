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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;
const int mod = 1000000007;

int a[MAXN];
int id[MAXN];
pii dp[MAXN];

void getMax(pii &a, pii b) {
    if (a.first < b.first) a = b;
    else if (a.first == b.first) {
        if ((a.second += b.second) >= mod) {
            a.second -= mod;
        }
    }
}

bool cmp(int x, int y) {
    return a[x] == a[y] ? x > y : a[x] < a[y];
}

void cdq(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    cdq(l, mid);
    for (int i = l; i <= r; ++i) id[i] = i;
    sort(id + l, id + r + 1, cmp);
    pii mx = pii(0, 0);
    for (int i = l; i <= r; ++i) {
        if (id[i] <= mid) getMax(mx, dp[id[i]]);
        else {
            pii temp = mx;
            ++temp.first;
            getMax(dp[id[i]], temp);
        }
    }
    cdq(mid + 1, r);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = pii(1, 1);
    }
    cdq(0, n - 1);
    pii ans = pii(0, 0);
    for (int i = 0; i < n; ++i) {
//        prln(ans.second)
        getMax(ans, dp[i]);
    }
    printf("%d\n", ans.second);
    return 0;
}
