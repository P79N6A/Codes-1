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

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, a, b;
    while (cin >> n && n) {
        int ans = 0, mx = 8;
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b;
            if (a + b > mx) {
                mx = a + b;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
