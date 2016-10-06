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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

struct P {
    int x, dep, id;
    bool operator < (const P&t)const {
        return dep > t.dep;
    }
}d[MAXN];


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int n, l, d;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &d[i].x, &d[i].dep);
            d[i].id = i;
        }
        sort(d, d + n);
    }
    return 0;
}
