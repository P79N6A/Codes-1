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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e3;

struct C {
    int mi, mx;
    bool operator < (const C &t)const {
        return mx > t.mx;
    }
}c[MAXN], b[MAXN];

bool cmp(C a, C b) {
    if (a.mi == b.mi) return a.mx < b.mx;
    return a.mi < b.mi;
}

int main()
{
    int cc, ll; scanf("%d%d", &cc, &ll);
    for (int i = 0; i < cc; ++i) scanf("%d%d", &c[i].mi, &c[i].mx);
    for (int i = 0; i < ll; ++i) scanf("%d%d", &b[i].mi, &b[i].mx);
    sort(c, c + cc, cmp);
    sort(b, b + ll, cmp);

    priority_queue<C, vector<C> > pq;
    int x = 0, ans = 0;
    for (int i = 0; i < ll; ++i) {
        for (; x < cc; ++x) {
            if (c[x].mi <= b[i].mi) pq.push(c[x]);
            else break;
        }
        while (b[i].mx && pq.size()) {
            if (pq.top().mx >= b[i].mi) ++ans, --b[i].mx;
            pq.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}
