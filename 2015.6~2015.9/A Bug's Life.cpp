#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e3 + 111;

int p[MAXN], ran[MAXN], rex[MAXN];

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (ran[x] > ran[y]) p[y] = x;
    else
    {
        p[x] = y;
        if (ran[x] == ran[y]) ++ran[y];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t, a, b, k; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        printf("Scenario #%d:\n", kase);
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= 2 * n; ++i) p[i] = i, ran[i] = 0, rex[i] = 0;
        bool flag = 1;
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) flag = 0;
            if (!rex[a]) rex[a] = b;
            else unite(rex[a], b);
            if (!rex[b]) rex[b] = a;
            else unite(rex[b], a);
        }
        if (flag) printf("No suspicious bugs found!\n\n");
        else printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
