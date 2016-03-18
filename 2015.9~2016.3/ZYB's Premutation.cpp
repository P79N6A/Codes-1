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
const int MAXN = 5e4 + 111;

int num[MAXN], ans[MAXN];
bool has[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(has, 0, sizeof has);
        for (int i = 1; i <= n; ++i) scanf("%d", num + i);
        int up = n;
        for (int i = n; i > 0; --i)
        {
            int large = num[i] - num[i - 1], cur;
            ans[i] = up - large;
            for (int j = ans[i]; ; --j)
            {
                if (!has[j])
                {
                    ans[i] = j;
                    has[j] = 1;
                    if (j == up) --up;
                    break;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (i != 1) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
