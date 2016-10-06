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
const int MAXN = 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k; cin >> k;
    for (int i = 0; i < 12; ++i) cin >> a[i];
    sort(a, a + 12);
    int ans = 0, mon = 0;
    for (int i = 11; i >= 0; --i) {
        if (ans >= k) break;
        ans += a[i];
        ++mon;
    }
    if (ans < k) puts("-1");
    else cout << mon << '\n';
    return 0;
}
