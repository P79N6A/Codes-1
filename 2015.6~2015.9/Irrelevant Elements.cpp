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
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 111;
bool isnot[MAXN];
int e[MAXN];
vector<int> ans, prime;

void add_fac(int n)
{
    int up = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= up; ++i)
    {
        if (n % i == 0) prime.push_back(i);
        int len = prime.size()-1;
        while(n % i == 0) {e[len]++; n /= i;}
    }
    if (n > 1)
    {
        prime.push_back(n);
        e[prime.size() - 1] = 1;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (cin >> n >> m)
    {
        prime.clear(), ans.clear();
        memset(e, 0, sizeof e);
        memset(isnot, 0, sizeof isnot);
        --n;
        add_fac(m);
        int len = prime.size();
        for (int i = 0; i < len; ++i)
        {
            int p = prime[i], need = e[i], cur_e = 0;
            for (int k = 1; k <= n/2; ++k)
            {
                int x = n - k + 1;
                while(x % p == 0) {++cur_e; x /= p;}
                x = k;
                while(x % p == 0) {--cur_e; x /= p;}
                if (cur_e < need) isnot[k] = 1;
            }
        }
        for (int i = 1; i <= n/2; ++i)
            if (!isnot[i]) ans.push_back(i);
        if(!ans.empty())
        {
            int p = ans.size() - 1;
            if (ans[p] * 2 == n) --p;
            for (int i = p; i >= 0; --i)
                ans.push_back(n - ans[i]);
            cout << ans.size() << '\n' << ans[0] + 1;
            for (int i = 1; i < ans.size(); ++i)
                cout << ' ' << ans[i] + 1;
        }
        else cout << 0 << '\n';
        cout << '\n';
    }
    return 0;
}
