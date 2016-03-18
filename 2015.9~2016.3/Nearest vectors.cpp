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
#define double long double // 使用long double
using namespace std;

const int MAXN = 1e5 + 111;

struct K{
    double k;
    int id;
    bool operator < (const K& t)const
    {
        return k < t.k;
    }
}kk[MAXN];

int main()
{
    int n; scanf("%d", &n);
    double pi = acos(-1);
    int x, y;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x, &y);
        kk[i].k = atan2(y , x);
        kk[i].id = i;
        //printf("kk[i].k = %.18lf\n", kk[i].k);
    }
    sort(kk + 1, kk + 1 + n);
    int ans1 = kk[1].id, ans2 = kk[n].id;  // 最后一个和第一个要特判下
    double mi = kk[1].k + 2 * pi - kk[n].k;
    for (int i = 1; i < n; ++i)
    {
        double del = kk[i + 1].k - kk[i].k;
        if (del < mi)
        {
            mi = del;
            ans1 = kk[i].id;
            ans2 = kk[i + 1].id;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
