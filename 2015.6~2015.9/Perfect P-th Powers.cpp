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
int ans;

void phi(ll n)
{
    int m = (int)sqrt(abs(n) + 0.5);
    for (int i = 2; i <= m; ++i)
    {
        int temp;
        if (n % i == 0)
        {
            int cnt = 0, temp = n;
            while (temp % i == 0) {++cnt; temp /= i;}
            if (temp == 1)
                ans = max(ans, cnt);
            cnt = 0, temp = n;
            while (temp % (-i) == 0) {++cnt; temp /= -i;}
            if (temp == 1)
                ans = max(ans, cnt);
        }
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n;
    while (cin >> n && n)
    {
        ans = 1;
        phi(n);
        cout << ans << '\n';
    }
    return 0;
}

