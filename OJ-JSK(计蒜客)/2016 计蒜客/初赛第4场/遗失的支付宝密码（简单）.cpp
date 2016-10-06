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

unsigned int ans = 0, temp = 0;

int main()
{
    unsigned int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            ans += m;
        }
        if (i == 2) {
            ans += m * (m - 1);
        }
        if (i == 3) {
            ans += m * (m - 1) * m;
        }
        if (i == 4) {
            ans += m * (m - 1) * m * m;
            ans -= m * (m - 1);
        }
        if (i == 5) {
            temp += m * (m - 1) * m * m;
            temp -= m * (m - 1);
            ans += temp * m;
        }
    }
    cout << ans << '\n';
    return 0;
}
