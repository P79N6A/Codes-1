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
const int MAXN = 3e4 + 111;

int p[MAXN];

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int a, int b)
{
    a = find(a), b = find(b);
    p[a] = b;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k, x, last;
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        for (int i = 0; i <= n; ++i) p[i] = i;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &k);
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &x);
                if (j > 0)
                {
                    unite(last, x);
                }
                last = x;
            }
        }
        int ans = 0, targe = find(0);
        for (int i = 0; i <= n; ++i)
        {
            if (find(i) == targe)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
