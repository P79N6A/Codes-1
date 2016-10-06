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
const int MAXN = 1111;

struct P {
    int id, time, pro;
    P(int a, int b, int c) {
        id = a, time = b, pro = c;
    }
    bool operator < (const P&t) const {
        if (t.time == time) return id > t.id;
        return t.time > time;
    }
};
set<P> s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    int l, r, t, c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &l, &r, &t, &c);
        for (int i = l; i <= r; ++i) {
            s[i].insert(P(i, t, c));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i].size() == 0) continue;
        P temp = *s[i].begin();
        //prln(temp.time)
        ans += temp.pro;
    }
    printf("%d\n", ans);
    return 0;
}
