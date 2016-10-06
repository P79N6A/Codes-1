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
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;
int fib[MAXN], cir[1011];
vector<int> v[1002];

void init()
{
    for (int i = 1; i <= 1000; ++i)
    {
        fib[0] = 0, fib[1] = 1 % i;
        v[i].push_back(0);
        v[i].push_back(fib[1]);
        int cnt = 0;
        for (int j = 2; j <= 1000010; ++j)
        {
            fib[j] = fib[j - 1] + fib[j - 2];
            fib[j] %= i;
            v[i].push_back(fib[j]);
            if (fib[j] == fib[1]) ++cnt;
            else cnt = 0;
            if (cnt == 2)
            {
                cir[i] = j - 2;
                break;
            }
        }
        //cout << "cir[" << i << "] = " << cir[i] << '\n';
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int n;
    ll t, a, b; cin >> t;
    while (t --)
    {
        cin >> a >> b >> n;
        ll ans = 1;
        while(b)
        {
            if(b & 1)
                ans = ((a%cir[n])*(ans%cir[n]))%cir[n];
            a = ((a%cir[n])*(a%cir[n]))%cir[n];
            b >>= 1;
        }
        //cout << ans <<"======\n";
        cout << v[n][ans] << '\n';
    }
    return 0;
}

