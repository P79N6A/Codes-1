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
const int MAXN = 1e5 + 111;

ll ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    ans[1] = 2;
    for (ll i = 2; i <= 1e5; ++i) {
        ans[i] = i * (i + 1) * (i + 1) - (i - 1);
    }
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
    }
    return 0;
}
