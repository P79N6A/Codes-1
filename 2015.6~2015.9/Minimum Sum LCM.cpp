#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = (1 << 17);
ll n;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    while (cin >> n && n)
    {
        ll ans = 0, cnt = 0;
        int up = sqrt(n) + 2;
        for (int i = 2; i <= up; ++i)
        {

            if (n % i == 0)
            {
                ++cnt;
                ll temp = 1;
                while (n % i == 0)
                {
                    temp *= i;
                    n /= i;
                }
                ans += temp;
            }
        }
        if (n > 1)
        {
            ans += n;
            ++cnt;
        }
        cout << "Case " << ++kase << ": ";
        if (cnt == 0) cout << n + 1 << '\n';
        else if (cnt == 1)
        {
            cout << ans + 1 << '\n';
        }
        else cout << ans << '\n';
    }
    return 0;
}

