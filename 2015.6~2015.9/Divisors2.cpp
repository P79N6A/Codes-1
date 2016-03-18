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
int l, r, ccnt;

void solve(int n)
{
    ccnt = 0;
    int up = sqrt(n + 0.5);
    for (int i = 1; i <= up; ++i)
    {
        if (n % i == 0)
        {
            if (n / i != i)
                ccnt += 2;
            else ++ccnt;
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t --)
    {
        cin >> l >> r;
        int ans = 0, cnt = 0;
        for (int i = l; i <= r; ++i)
        {
            solve(i);
            if (ccnt > cnt)
            {
                ans = i;
                cnt = ccnt;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, ans, cnt);
    }
    return 0;
}
