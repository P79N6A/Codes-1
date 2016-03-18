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

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int w, h;
        if (!(n % 2)) w = n / 2, h = n + 1;
        else w = (n + 1) / 2, h = n;
        printf("%d %d\n", w, h);
        int x = 1, y = 1, cnt = 0, addy = 1, turn = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                printf("%d %d", x, y);
                if (j < i) printf(" ");
                ++cnt;
                if (cnt / h == turn)
                {
                    addy = -addy;
                    x += 1;
                    ++turn;
                }
                else y += addy;
            }
            printf("\n");
        }
    }
    return 0;
}
