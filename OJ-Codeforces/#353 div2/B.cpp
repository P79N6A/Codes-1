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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll l = max((ll)1, max(max(1 + c - b, 1 + d - a), 1 + c + d - a - b));
    ll r = min(n, min(min(n + d - a, n + c + d - a - b), n + c - b));
    if (r < l) cout << 0 << '\n';
    else cout << n * (r - l + 1) << '\n';
    return 0;
}
