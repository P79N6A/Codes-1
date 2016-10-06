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
int prime[MAXN], len, ans;
bool is[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    prime[len++] = 0;
    for (int i = 2; i <= MAXN - 111; ++i)
    {
        if (!is[i])
        {
            prime[len++] = i;
            for (int j = i*i; j <= MAXN - 111; j += i)
                is[j] = 1;
        }
    }
    for (int i = 1; i < len; ++i)
        prime[i] += prime[i - 1];
    int n;
    while (cin >> n && n)
    {
        ans = 0;
        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j)
            {
                if (prime[j] - prime[i] == n)
                    ++ans;
            }
        cout << ans << '\n';
    }
    return 0;
}

