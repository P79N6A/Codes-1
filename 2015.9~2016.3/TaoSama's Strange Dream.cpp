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
const int MAXN = 1e5 + 111;

int cnt[MAXN];
int num[MAXN * 2];

int main()
{
    int n, t, k; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &k);
        int mod = 2 * n - 2;
        if (mod == 0)
        {
            printf("YES\n");
            continue;
        }
        memset(cnt, 0, sizeof(int) * (n + 1));
        num[n - 1] = n - 1;
        for (int i = 1; i < n - 1; ++i)
        {
            num[2 * n - i - 2] = i;
            num[i] = i;
        }

        //for (int i = 0; i < 2 * n - 2; ++i) cout << num[i] << ' ';
        bool flag = 0;
        int ans = 0;
        k %= mod;
        for (int i = 0; ; i += k)
        {
            i %= mod;
            if (!cnt[num[i]]) ++ans;
            ++cnt[num[i]];
            if (ans == n)
            {
                flag = 1;
                break;
            }
            if (cnt[num[i]] > 1) break;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
