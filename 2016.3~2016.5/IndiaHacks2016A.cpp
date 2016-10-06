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

int a[60];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    bool flag = 0;
    n = unique(a, a + n) - a;
    for (int i = 0; i < n - 2; ++i) {
        if (a[i + 1] - a[i] < 2 && a[i + 2] - a[i + 1] < 2)
            flag = 1;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
