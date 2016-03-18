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
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;

int p[MAXN];

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    p[x] = y;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, a, b, kase = 0;
    while (scanf("%d%d", &n, &m) && n)
    {
        for (int i = 1; i <= n; ++i) p[i] = i;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        set<int> ans;
        for (int i = 1; i <= n; ++i)
        {
            ans.insert(find(i));
        }
        printf("Case %d: %d\n", ++kase, ans.size());
    }
    return 0;
}
