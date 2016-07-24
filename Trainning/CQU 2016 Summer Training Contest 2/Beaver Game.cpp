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
const int MAXN = 1e6 + 111;

bool ok(int n, int m, int k) {
    if (n % 2 == 0) return 0;
    if (m == 1) return 0;
    bool ret = 0;
    for (int i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            if (i >= k) ret |= !ok(m / i, i, k);
            if (m / i >= k) ret |= !ok(i, m / i, k);
            if (ret) break;
        }
    }
    if (k == 1) ret |= !ok(m, 1, k);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    while (cin >> n >> m >> k) {
        if (ok(n, m, k)) {
            puts("Timur");
        }
        else puts("Marsel");
    }
    return 0;
}
