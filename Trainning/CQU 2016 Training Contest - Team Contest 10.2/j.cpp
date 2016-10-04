
#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
ll n, m, p;
ll get(ll x1, ll x2){
    if(x1<0||x2<0) return 0;
    ll y1 = x1/p;
    ll y2 = x2/p;
    ll ans = y1*y2*p;
    x1 %= p, x2 %= p;
    ans += y2*(x1+1) + y1*(x2+1);
    ll x = 0;
    ll l = max(m - x2, 0ll), r = min(x1, m);
    if(r>=l) ans += r-l+1;
    l = max(p+m-x2, 0ll), r = min(p-1, x1);
    if(r>=l) ans += r-l+1;
    return ans;
}

/*
ll eget(ll x1, ll x2) {
    ll up1 = min(x1, p);
    ll up2 = min(x2, p);
    ll ans = 0;
    ll y1 = min(up2, m);
    ll x1 = max(0ll, p - up1);
    if(y1 >= x1) ans = ans + y1 - x1 + 1;
}*/
int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll a, b, c, d;
    int t;
    int kase = 0;
    scanf("%d",&t);
    while(t--){
        cin>>a>>b>>c>>d>>p>>m;
        ll ans = get(b, d) + get(a-1, c-1);
       // prln(ans);
        ans -= (get(a-1, d) + get(c-1, b));
        ll mu = (b-a+1)*(d-c+1);
      //  prln(ans);prln(mu);
        ll gg = __gcd(mu, ans);
        ans/=gg;
        mu/=gg;
       // prln(gg);
        printf("Case #%d: %lld/%lld\n",++kase, ans,mu);
    }
    return 0;
}
