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

int a[40];

char get(int k) {
    if (k == 0) return 'R';
    else if (k == 1) return 'G';
    else return 'B';
}

int main()
{
    int t, m;
    ll n;
    cin >> t;
    while (t --) {
        cin >> m >> n;
        a[m] = n % 3;
        n /= 3;
        for (int i = m - 1; i >= 1; --i) {
            a[i] = n % 3;
            n /= 3;
        }
        for (int i = 1; i <= m; ++i) cout << get(a[i]);
        cout << '\n';
    }
    return 0;
}
