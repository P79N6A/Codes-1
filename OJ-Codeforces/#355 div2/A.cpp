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
const int MAXN = 1e6 + 111;

int a;

int main()
{
    #ifdef LOCAL
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, h;
    cin >> n >> h;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > h) ans += 2;
        else ans += 1;
    }
    cout << ans << '\n';
    return 0;
}
