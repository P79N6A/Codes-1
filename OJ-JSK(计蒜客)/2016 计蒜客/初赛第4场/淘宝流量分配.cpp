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
const int MAXN = 1e4 + 111;

int a[MAXN];
int dp[MAXN];
int mx[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) ans += a[i];
    }
    int temp = a[n - 1];
    int temp2 = 0, temp3 = 0;
    for (int i = n - 3; i >= 0; --i) {
        if (i % 2) temp2 += a[i];
        else temp3 += a[i];
    }
    cout << max(max(ans, temp + temp2), temp + temp3) << '\n';
    return 0;
}
