#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
int n, u[MAXN], v[MAXN], w[MAXN], p[1111], r[MAXN], up;

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool cmp(int a, int b)
{
    return w[a] < w[b];
}

int kruskal()
{
    int ans = 0;
    for (int i = 0; i <= n; ++i) p[i] = i;
    sort(r, r + up, cmp);
    for (int i = 0; i < up; ++i)
    {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);
        if (x != y){ ans += w[e]; p[x] = y;}
    }
    return ans;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while(~scanf("%d", &n))
    {
        int x;
        up = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d", &x);
            u[up] = n, v[up] = i;
            w[up] = x;
            r[up] = up;
            ++up;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                scanf("%d", &x);
                u[up] = i, v[up] = j;
                w[up] = x;
                r[up] = up;
                ++up;
            }
        }
        cout << kruskal() << '\n';
    }
    return 0;
}

