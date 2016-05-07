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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int a[MAXN];

struct P {
    int b, c, numb, numc, id;
    bool operator < (const P &t) const {
        if (numb == t.numb) return numc > t.numc;
        return numb > t.numb;
    }
}p[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &p[i].b);
            p[i].numb = upper_bound(a, a + n, p[i].b) - lower_bound(a, a + n, p[i].b);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &p[i].c);
            p[i].numc = upper_bound(a, a + n, p[i].c) - lower_bound(a, a + n, p[i].c);
            p[i].id = i + 1;
        }
        sort(p, p + m);
        printf("%d\n", p[0].id);
    }
    return 0;
}
