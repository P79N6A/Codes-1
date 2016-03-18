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
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

ll a[MAXN], qv[MAXN], q[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            a[n + i] = a[i];
        }

        int l = 0, r = 0;
        ll ansl = 1, ansr = 1, ans = a[1], sum = 0;
        for (int i = 1; i <= n << 1; ++i)
        {
            sum += a[i];
            while (l < r && qv[r - 1] >= sum) --r;
            q[r] = i; qv[r] = sum; ++r;
            if (i > m)
            {
                if (i != q[l])
                {
                    if (sum - qv[l] > ans || (sum - qv[l] == ans && i - q[l] < ansr - ansl + 1))
                    {
                        ans = sum - qv[l];
                        ansl = q[l] + 1;
                        ansr = i;
                        // pr(ansl);pr(ansr);
                    }
                    if (q[l] == i - m) ++l;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > ans)
            {
                ansl = ansr = i;
                ans = a[i];
            }
        }
        printf("%lld %lld %lld\n", ans, (ansl - 1)%n + 1, (ansr - 1)%n + 1);
    }
    return 0;
}
