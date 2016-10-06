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

int main()
{
    int n;
    while (cin >> n) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        ll half = sum/2;
        sort(a, a + n);
        ll t = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (t + a[i] <= half) t += a[i];
        }
        cout << t - (sum - t) + 1 << '\n';
    }
    return 0;
}
