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
const int MAXN = 1e6 + 111;

struct Point{
    int x, y;
}p[10];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    while (t --)
    {
        for (int i = 0; i < 4; ++i)
        {
            scanf("%d %d", &p[i].x, &p[i].y);
            if (p[i].x > p[i].y) swap(p[i].x, p[i].y);
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
