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
#define ull unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;

ull a[MAXN];
ull ans[MAXN];
int pos[MAXN];
struct P {
    int l, r, id;
    bool operator < (const P&t)const {
        if (pos[l] == pos[t.l]) return r < t.r;
        return pos[l] < pos[t.l];
    }
}p[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        int del = ceil(sqrt(1.0 * n));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[i] = (i - 1) / del;
        }
        for (int i = 0; i < m; ++i) {
            cin >> p[i].l >> p[i].r;
            p[i].id = i;
        }
        sort(p, p + m);
    }
    return 0;
}
