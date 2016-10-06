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
const int MAXN = 5e5 + 111;

struct N {
    int id;
    int nx[26];
    void init() {
        id = -1;
        memset(nx, -1, sizeof nx);
    }
}node[MAXN * 10];

int cnt, par[MAXN], deg[MAXN], len;

void init() {
    cnt = len = 0;
    node[0].init();
}

int insert(char *s) {
    int i = 0, p = 0;
    while (s[i]) {
        int x = s[i] - 'a';
        if (node[p].nx[x] == -1) {
            node[++cnt].init();
            node[p].nx[x] = cnt;
        }
        p = node[p].nx[x];
        ++i;
    }
    par[len] = len;
    deg[len] = 0;
    node[p].id = len;
    return len++;
}

int query(char *s) {
    int i = 0, p = 0;
    while (s[i]) {
        int x = s[i] - 'a';
        if (node[p].nx[x] == -1) return insert(s);
        p = node[p].nx[x];
        ++i;
    }
    return node[p].id;
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool ok() {
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (deg[i] % 2) ++ret;
        if (find(i) != find(0)) return 0;
    }
    if (ret != 0 && ret != 2) return 0;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    char str1[15], str2[15];
    while (~scanf("%s%s", str1, str2)) {
        int u = query(str1);
        int v = query(str2);
        ++deg[u];
        ++deg[v];
        u = find(u), v = find(v);
        par[u] = v;
    }

    if (ok()) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
