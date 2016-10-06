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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

ll a[MAXN];
map<ll, int> mp;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        mp.clear();
        int mx = 0;
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i]);
            a[i] += a[i - 1];
            mx = max(mx, ++mp[a[i]]);
        }
        printf("%d\n", n - mx);
    }
    return 0;
}
