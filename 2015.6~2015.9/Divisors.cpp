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
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int l, r, t; cin >> t;
    while (t --)
    {
        cin >> l >> r;
        int mx = -1, num;
        for (int i = l; i <= r; ++i)
        {
            int cnt = 0;
            for (int j = 1; j <= sqrt(i); ++j)
            {
                if (i % j == 0)
                {
                    ++cnt;
                    if (i / j != j) ++cnt;
                }
            }
            if (cnt > mx) mx = cnt, num = i;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, num, mx);
    }
    return 0;
}
