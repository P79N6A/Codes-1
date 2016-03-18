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
const int MAXN = 1e4 + 111;

struct S {
    int d, f;
    bool operator < (const S&t)const{
        return f < t.f;
    }
}s[MAXN];

bool cmp(S a, S b) {
    return a.d > b.d;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int l, p, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &s[i].d, &s[i].f);
    scanf("%d%d", &l, &p);
    sort(s, s + n, cmp);
    s[n].d = 0, s[n].f = 0;

    int ans = 0;
    priority_queue<S, vector<S> > pq;
    for (int i = 0; i <= n && ans >= 0; ++i) {
        p -= (l - s[i].d);
        while (p < 0) {
            if (pq.empty()) {
                ans = -1;
                break;
            }
            ++ans;
            p += pq.top().f;
            pq.pop();
        }
        l = s[i].d;
        pq.push(s[i]);
    }

    printf("%d\n", ans);
    return 0;
}
