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

int dis[MAXN];
int n, m;

bool ok(int up) {
    int ret = 0;
    int base = 0;
    for (int i = 0; i < n; ++i) {
        if (dis[i] - base < up) {
            if (++ret > m) return 0;
        }
        else base = dis[i];
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int L;
    while (~scanf("%d%d%d", &L, &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &dis[i]);
        }
        sort(dis, dis + n);
        int l = 0, r = L, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
