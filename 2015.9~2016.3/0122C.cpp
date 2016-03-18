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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int a[111], b[111];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j <= m; ++j) {
        cin >> b[j];
    }
    if (n > m) {
        if (!(a[0] < 0 && b[0] < 0 ) && (a[0] < 0 || b[0] < 0)) cout << '-';
        cout << "Infinity\n";
    }
    else if (n == m){
        int gcd = abs(__gcd(a[0], b[0]));
        if (a[0] * b[0] < 0) cout << '-';
        cout << abs(a[0]) / gcd << '/' << abs(b[0]) / gcd << '\n';
    }
    else {
        cout << 0 << '/' << 1 << '\n';
    }
    return 0;
}
