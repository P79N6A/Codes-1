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
const int MAXN = 5e5 + 111;

char s[MAXN];
char op[MAXN];
int l[MAXN], r[MAXN];
int fr[MAXN], sta[MAXN];

int findl(int x) {
    return x == l[x] ? x : l[x] = findl(l[x]);
}

int findr(int x) {
    return x == r[x] ? x : r[x] = findr(r[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, p;
    while (~scanf("%d%d%d", &n, &m, &p)) {
        scanf("%s", s + 1);
        int top = 1;
        l[0] = r[0] = 0;
        l[n + 1] = r[n + 1] = n + 1;
        for (int i = 1; i <= n; ++i) {
            l[i] = r[i] = i;
            if (s[i] == ')') {
                int x = sta[--top];
                fr[x] = i;
                fr[i] = x;
            }
            else sta[top++] = i;
        }
        scanf("%s", op);
        for (int i = 0; i < m; ++i) {
            //pr(p);
            if (op[i] == 'L') {
                p = findl(p - 1);
            }
            else if (op[i] == 'R') {
                p = findr(p + 1);
            }
            else {
                int u = p, v = fr[p];
                if (u > v) swap(u, v);
                r[u] = findr(v + 1);
                l[v] = findl(u - 1);
                p = r[u];
                if (p == n + 1) p = l[v];
            }
            //pr(p);pr("======")
        }
        for (p = findr(1); p <= n;) {
            printf("%c", s[p]);
            p = findr(p + 1);
        }
        putchar('\n');
    }
    return 0;
}
