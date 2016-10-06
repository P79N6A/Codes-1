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
    int m, n;
    while (cin >> m >> n) {
        int ans = m;
        n = (n + 1) / 2;
        for (int i = 1; i < n; ++i) {
            ans += m + m - 1;
            --m;
        }
        cout << ans << '\n';
    }
    return 0;
}
