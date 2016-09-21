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
const int MAXN = 1e5 + 11;

ll dp[MAXN][300];
int a[MAXN];
ll mx[300];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%x", &a[i]);
    }
    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 256; ++j) {

        }
    }
    ll ans = 0;
    return 0;
}
