#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

void print(int n, char a)
{
    for (int i = 0; i < n; ++i)
        putchar(a);
}

int getlen(ll num)
{
    int ret = 0;
    while(num)
    {
        ++ret;
        num /= 10;
    }
    return ret;
}

int main()
{
    int n;
    while (cin >> n)
    {
        ll up = 1, down = 1, divide;
        for (int i = 2; i <= n; ++i)
        {
            up = i * up + down;
            down *= i;
            divide = __gcd(up, down);
            up /= divide;
            down /= divide;
        }
        up *= n;
        divide = __gcd(up, down);
        up /= divide;
        down /= divide;
        int ans = up / down;
        up = up % down;

        int len1 = getlen(ans), len2 = getlen(up), len3 = getlen(down);
        if (up == 0) cout << ans << '\n';
        else
        {
            print(len1 + 1, ' '); cout << up << '\n';
            cout << ans << ' '; print(max(len2, len3), '-'); cout << '\n';
            print(len1 + 1, ' '); cout << down << '\n';
        }
    }
    return 0;
}
