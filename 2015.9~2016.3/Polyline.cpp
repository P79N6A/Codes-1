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

int x[3], y[3];

int main()
{

    for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];

    if (x[0] == x[1] && x[1] == x[2]) cout << 1 << '\n';
    else if (y[0] == y[1] && y[1] == y[2]) cout << 1 << '\n';
    else if (x[0] == x[1] && || x[0] == x[2] || x[1] == x[2]) cout << 2 << '\n';
    else if (y[0] == y[1] || y[0] == y[2] || y[1] == y[2]) cout << 2 << '\n';
    else cout << 3 << '\n';
    return 0;
}
