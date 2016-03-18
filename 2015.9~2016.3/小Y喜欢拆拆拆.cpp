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
const int MAXN = 1e6 + 111;

int main()
{
    int n, up, ans;
    while (cin >> n)
    {
        while (1)
        {
            ans = 0;
            up = n;
            for (int i = 2; i * i <= up; ++i)
            {
                while (n % i == 0)
                {
                    ans += i;
                    n /= i;
                }
            }
            if (ans == 0) break;
            if (n > 1) ans += n;
            n = ans;
            if (n == up)
            {
                n = -1;
                break;
            }
        }
        printf("%d\n", n);
    }
    return 0;
}
