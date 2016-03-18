#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 1e4 + 111;

int p[MAXN];
struct N{
    int p, d;
    bool operator < (const N& t)const
    {
        return p > t.p;
    }
}a[MAXN];

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int ans = 0;
        for (int i = 0; i <= 1e4 + 11; ++i) p[i] = i;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &a[i].p, &a[i].d);
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i)
        {
            int temp = find(a[i].d); // 查找可用的日子
            if (temp > 0)
            {
                p[temp] = temp - 1; // 使用之后将日期向前挪
                ans += a[i].p;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}