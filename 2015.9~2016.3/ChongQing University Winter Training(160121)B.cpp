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
const int MOD = 1e6 + 3;

ll quick_pow(int a, int x) {
    ll base = a;
    int p = x;
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        p >>= 1;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0) cout << 1 << '\n';
    else cout << quick_pow(3, n - 1) << '\n';
    return 0;
}
