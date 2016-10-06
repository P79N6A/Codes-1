#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <time.h>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
const int MAXN = 2e6 + 11;
typedef long long ll;
ll cntt[10] = {0};

ll qt[10][MAXN];

void dfs(ll num, ll left, int cnt, int i)
{
    if (cnt == 0)
    {
        qt[i][cntt[i]]=num;
        ++cntt[i];
        //cout << i << cntt[i] << endl;
        return;
    }
    int y = left / pow(10, cnt - 1);
    if (y == 0)
        dfs(num * 10, left/(pow(10,cnt-1)),cnt-1,i);
    else {
        if(num%10+y<=9) dfs(num*10+num%10+y,left%(ll)(pow(10,cnt-1)),cnt-1,i);
        if(num%10-y>=0) dfs(num*10+num%10-y,left%(ll)(pow(10,cnt-1)),cnt-1,i);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    qt[1][0] = 7;
    //qt[1].push(7);
    cntt[1] = 1;
    for(int i=2;i<=9;i++){
        for (ll k = 0; k < cntt[i - 1]; ++k){
            ll x= qt[i - 1][k];
            //cout << x << endl;
            for(int j=1;j<=9;j++){
                dfs(j,x,i-1,i);
            }
        }
    }
    ll a,b;
    while(scanf("%lld%lld",&a,&b)==2){
        ll ans = 0;
        for (int i = 1; i <= 9; ++i)
        {
            //cout << cntt[i];
            for (int j = 0; j < cntt[i]; ++j)
            {
                //printf("%lld\n", qt[i][j]);
                if (qt[i][j] <= b && qt[i][j] >= a)
                    ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
