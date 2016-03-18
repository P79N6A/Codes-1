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
    ll n, m;
    while (cin >> n >> m && n)
    {
        cout << n << ' ' << m << ' ';
        ll up = m * n - 1, down = n - 1;
        if (n == 1)
        {
            if (m == 1) cout << "Multiple\n";
            else cout << "Impossible\n";
        }
        else if (up % down) cout << "Impossible\n";
        else cout << up / down << '\n';
    }
    return 0;
}
