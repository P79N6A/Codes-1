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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

struct P {
    int c, p, id;
    bool operator < (const P&t)const {
        return p < t.p;
    }
}a[MAXN], b[MAXN];

bool cmp(P a, P b) {
    if (a.c == b.c) return a.id < b.id;
    return a.c < b.c;
}

bool cmp2(P a, P b) {
    return a.id < b.id;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].c);
            a[i].id = i;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i].c);
            b[i].id = i;
        }
        sort(a + 1, a + 1 + n, cmp);
        sort(b + 1, b + 1 + n, cmp);
        bool flag = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i].c != b[i].c) flag = 0;
            else a[i].p = b[i].id;
        }
        sort(a + 1, a + 1 + n, cmp2);
        sort(b + 1, b + 1 + n, cmp2);
        //for (int i = 1; i <= n; ++i) pr(a[i].p)
        int l, r;
        while (m --) {
            scanf("%d%d", &l, &r);
            sort(a + l, a + r + 1);
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i].c != b[i].c) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
