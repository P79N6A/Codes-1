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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    ll mx = d / k - (d % k == 0);
    ll lef = d - mx * k;
    ll ans = mx * k * a + max((ll)0, mx - 1) * t;
    ll time1 = (mx != 0) * t + lef * a;
    ll time2 = lef * b;
    ll ans1 = ans + min(time1, time2);
    ll ans2 = min(k, d) * a + max((ll)0, d - k) * b;
    cout << min(ans1, ans2) << endl;
    return 0;
}
