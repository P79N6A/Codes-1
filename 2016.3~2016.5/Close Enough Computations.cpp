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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double n, a, b, c;
    int x, y, z;
    while (cin >> n >> x >> y >> z && (x|y|z)) {
        a = x; b = y; c = z;
        a = max(0.0, a - 0.5);
        b = max(0.0, b - 0.5);
        c = max(0.0, c - 0.5);
        double temp = a * 9 + b * 4 + c * 4;
        int mi = round(temp);
        a = x; b = y; c = z;
        a += 0.499999;
        b += 0.499999;
        c += 0.499999;
        temp = a * 9 + b * 4 + c * 4;
        int mx = round(temp);
        if (mi <= n && n <= mx) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
