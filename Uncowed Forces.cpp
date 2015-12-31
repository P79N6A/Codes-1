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
const int MAXN = 5;

double m[5], w[5], h1, h2;

int main()
{
    for (int i = 0; i < 5; ++i) cin >> m[i];
    for (int i = 0; i < 5; ++i) cin >> w[i];
    cin >> h1 >> h2;
    double ans = 100 * h1 - 50 * h2;
    for (int i = 0; i < 5; ++i)
    {
        ans += max(0.3 * (500 * (i + 1)), (1.0 - m[i] / 250.0)*(500.0 * (i + 1)) - 50 * w[i]);
    }
    cout << ans << '\n';
    return 0;
}
