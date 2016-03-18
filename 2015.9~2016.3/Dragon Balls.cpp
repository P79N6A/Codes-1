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
const int MAXN = 1e4 + 111;

int mv[MAXN], p[MAXN], in[MAXN];

int find(int x) {
    if (x == p[x]) {
        return p[x];
    }
    int temp = p[x];
    p[x] = find(p[x]);
    mv[x] += mv[temp];
    return p[x];
}

int main()
{
    int t, n, q;
    for (int kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%d%d", &n, &q);
        printf("Case %d:\n", kase);
        for (int i = 1; i <= n; ++i) {
            mv[i] = 0;
            in[i] = 1;
            p[i] = i;
        }
        int u, v;
        char op[2];
        while (q --) {
            scanf("%s %d", op, &u);
            if (op[0] == 'T') {
                scanf("%d", &v);
                u = find(u), v = find(v);
                if (u != v) {
                    ++mv[u];
                    p[u] = v;
                    in[v] += in[u];
                }
            }
            else {
                int x = u;
                u = find(u);
                printf("%d %d %d\n", u, in[u], mv[x]);
            }
        }
    }
    return 0;
}
