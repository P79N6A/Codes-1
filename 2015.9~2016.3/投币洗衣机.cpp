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
    int n, a, b, c;
    while (cin >> n >> a >> b >> c)
    {
        int sum = 0, x, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            sum += x;
            if (a <= sum && sum < b)
            {
                ans += 2;
                sum = 0;
            }
            else if (b <= sum && sum < c)
            {
                ans += 3;
                sum = 0;
            }
            else if (c <= sum)
            {
                ans += 4;
                sum = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
