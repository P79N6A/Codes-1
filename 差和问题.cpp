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
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll sum = 0, q, x, cnt = 0;
    scanf("%I64d%I64d", &n, &q);
    map<ll, bool> mp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%I64d", &x);
        bool judge = mp[x];
        if (judge) continue;
        else mp[x] = 1, sum += x, ++cnt;
    }

    int op;
    while (q --)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%I64d", &x);
            if (!mp[x])
            {
                mp[x] = 1;
                ++cnt;
                sum += x;
            }
        }
        else if (op == 2)
        {
            scanf("%I64d", &x);
            if (!mp[x]) printf("-1\n");
            else
            {
                mp[x] = 0;
                sum -= x;
                --cnt;
            }
        }
        else
        {

        }
    }
    return 0;
}
