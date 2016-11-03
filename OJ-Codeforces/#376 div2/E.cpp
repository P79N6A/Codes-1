#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	a[i] += a[i - 1];
    }
    int ans = a[n];
    for (int i = n - 1; i > 1; --i) {
    	ans = max(ans, a[i] - ans);
    }
    cout << ans << '\n';
    return 0;
}