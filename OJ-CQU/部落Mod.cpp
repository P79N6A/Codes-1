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
const int MAXN = 1e5 + 111;

int num[MAXN], tim[MAXN], par[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        num[i] = 1;
        tim[i] = 0;
    }
}

int find(int x) {
    if (x == par[x]) return x;
    int temp = find(par[x]);
    if (tim[par[x]] > tim[x]) {
        tim[x] = tim[par[x]];
        num[x] = 1;
        par[x] = x;
    }
    else par[x] = temp;
    return par[x];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        char op[2];
        int u, v;
        init(n);
        for (int i = 1; i <= m; ++i) {
            scanf("%s", op);
            if (op[0] == 'U') {
                scanf("%d%d", &u, &v);
                u = find(u), v = find(v);
                if (u != v) {
                    if (tim[u] <= tim[v]) {
                        par[v] = u;
                        num[u] += num[v];
                    }
                    else {
                        par[u] = v;
                        num[v] += num[u];
                    }
                }
            }
            else if (op[0] == 'D') {
                scanf("%d", &u);
                u = find(u);
                tim[u] = i;
                num[u] = 1;
            }
            else if (op[0] == 'S') {
                scanf("%d", &u);
                printf("%d\n", num[find(u)]);
            }
            else {
                scanf("%d%d", &u, &v);
                if (find(u) == find(v)) puts("Yes");
                else puts("No");
            }
        }
        //for (int i = 1; i <= n; ++i) pr(tim[i]);
    }
    return 0;
}
