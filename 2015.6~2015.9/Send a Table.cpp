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
const int INF = 0x3f3f3f3f, MAXN = 5e4 + 111;
int phi[MAXN];

void init()
{
    phi[1] = 1;
    for (int i = 2; i <= 50001; ++i) if (!phi[i])
    {
        for (int j = i; j <= 50001; j += i)
        {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    for (int i = 3; i <= 50001; ++i)
        phi[i] += phi[i - 1];
}

int main()
{
    init();
    int n;
    while (cin >> n && n)
    {
        if (n >= 2)
            cout << 2 * phi[n] + 1 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}
