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
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;
const ll up = 1e18;

ll hdp[MAXN], ldp[MAXN];

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        ldp[0] = 1;
        for (int j = i; j <= n; ++j) {
            ldp[j] += ldp[j - i];
            hdp[j] += hdp[j - i];
            if (ldp[j] >= up) {
                ldp[j] -= up;
                ++hdp[j];
            }
        }
    }
    if (hdp[n]) {
        cout << hdp[n];
        ll x = ldp[n];
        int cnt = 0;
        while (x) {
            ++cnt;
            x /= 10;
        }
        for (int i = 0; i < 18 - cnt; ++i) {
            cout << 0;
        }
        cout << ldp[n] << '\n';
    }
    else
        cout << ldp[n] << '\n';
    return 0;
}
