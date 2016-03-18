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
const int INF = 0x3f3f3f3f, MAXN = 1e4 + 111;
bool p[MAXN];
int e[MAXN];
vector<int> prime;

void init()
{
    for (int i = 2; i <= 10000; ++i)
    {
        if (!p[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= 10000; j+=i)
            {
                p[j] = 1;
            }
        }
    }
}

void add_integer(int n, int d)
{
    for (int i = 0; i < prime.size(); ++i)
    {
        while(n % prime[i] == 0)
        {
            n/=prime[i];
            e[i] += d;
        }
        if (n < prime[i]) return;
    }
}

void add_fac(int r, int l, int d)
{
    for (int i = r; i >= l; --i)
        add_integer(i, d);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int p, q, r, s;
    while (cin >> p >> q >> r >> s)
    {
        memset(e, 0, sizeof e);
        add_fac(p, q + 1, 1); add_fac(p - q, 1, -1);
        add_fac(r, s + 1, -1), add_fac(r - s, 1, 1);
        double ans = 1;
        for (int i = 0; i < prime.size(); ++i)
        {
            //cout << prime[i] << ' ' << e[i] << endl;
            ans *= pow(prime[i],e[i]);
        }
        printf("%.5f\n", ans);
    }
    return 0;
}

