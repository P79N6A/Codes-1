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
const int MAXN = 1e3 + 111;

int a[MAXN], lc[MAXN], rc[MAXN];

bool dfs(int &rt, int s, int t, int flag) {
    if (s > t) {
        return 1;
    }
    rt = s;
    int p = s;
    while (p < t && ((a[p + 1] < a[s]) ^ flag)) ++p;
    int q = p;
    while (q < t && ((a[q + 1] >= a[s]) ^ flag)) ++q;
    if (q < t) {
        return 0;
    }
    return (dfs(lc[rt], s + 1, p, flag) && dfs(rc[rt], p + 1, t, flag));
}

int cnt = 0, n;
void getans(int rt) {
    if (!rt) return;
    getans(lc[rt]);
    getans(rc[rt]);
    printf("%d", a[rt]);
    if (++cnt != n) putchar(' ');
    else putchar('\n');
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", a + i);
        int rt;
        if (dfs(rt, 1, n, 0) || dfs(rt, 1, n, 1)) {
            puts("YES");
            cnt = 0;
            getans(rt);
        }
        else puts("NO");
    }
    return 0;
}
