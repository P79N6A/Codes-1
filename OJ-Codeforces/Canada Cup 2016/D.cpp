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
#define pll pair<ll, ll>
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e5 + 111;

priority_queue<ll, vector<ll>, greater<ll> > up;
priority_queue<pll> down;


int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n;
    ll st, sw, t, w;
    scanf("%d%lld%lld", &n, &st, &sw);
    for (int i = 1; i < n; ++i) {
    	scanf("%lld%lld", &t, &w);
        if (t > st) {
            up.push(w - t + 1);
        }
        else {
            down.push(pll(t, w));
        }
    }
    int ans = up.size();
    while (up.size() && st - up.top() >= 0) {
        st -= up.top();
        up.pop();
        while (down.size() && st < down.top().first) {
            up.push(down.top().second - down.top().first + 1);
            down.pop();
        }
        ans = min(ans, (int)up.size());
    }
    printf("%d\n", ans + 1);
    return 0;
}